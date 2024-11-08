#include "mainwindow.h"

#include <QBitArray>
#include <QDialogButtonBox>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QOverload>
#include <QProgressDialog>
#include <QStandardPaths>
#include "filetree.h"
#include "hufEncode.h"
#include "hufDecode.h"
#include "ui_mainwindow.h"
#include "type.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  progressBar = ui->progressBar;
  compressionRateLabel = ui->compressionRateLabel;

  // 初始化视图树
  QTreeWidget *tree{ui->treeWidget};

  // 初始化进度条
  ui->progressBar->setRange(0, 100);
  ui->progressBar->setValue(0);
  ui->progressBar->hide();  // 隐藏进度条

  // 设置默认多选模式
  tree->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
  // 隐藏复选框
  ui->checkBox_useSeperateKeytoCompress->setVisible(false);
  ui->checkBox_useKeytoDecompress->setVisible(false);
  // 设置组件不可见
  ui->pushButton_compress->setVisible(false);
  ui->pushButton_decompress->setVisible(false);
  ui->lineEdit_pathDisplay->setVisible(false);
  ui->toolButton_selectPath->setVisible(false);

  // 连接菜单项与槽函数
  connect(ui->actionUseSeparateKeyToCompress, &QAction::triggered, this, &MainWindow::on_actionUseSeparateKeyToCompress_triggered);
  connect(ui->actionUseKeyToDecompress, &QAction::triggered, this, &MainWindow::on_actionUseKeyToDecompress_triggered);

  // Connections 将 添加文件 和 添加目录 的操作统一处理
  connect(ui->actFile_addDir, qOverload<bool>(&QAction::triggered), this,
          [this]() -> void {
            this->do_actFile_addNode_triggered(type::NodeType::Directory);
          });
  connect(ui->actFile_addFile, qOverload<bool>(&QAction::triggered), this,
          [this]() -> void {
            this->do_actFile_addNode_triggered(type::NodeType::File);
          });

  // Connections 将所有控制视图树的设置连接到同一个槽函数，统一处理
  connect(ui->actView_displayIcons, qOverload<bool>(&QAction::triggered), this,
          qOverload<>(&MainWindow::do_actView_triggered));
  connect(ui->actView_displayName, qOverload<bool>(&QAction::triggered), this,
          qOverload<>(&MainWindow::do_actView_triggered));
  connect(ui->actView_displaySize, qOverload<bool>(&QAction::triggered), this,
          qOverload<>(&MainWindow::do_actView_triggered));
  connect(ui->actView_displayPath, qOverload<bool>(&QAction::triggered), this,
          qOverload<>(&MainWindow::do_actView_triggered));
  connect(ui->actView_displayEditTime, qOverload<bool>(&QAction::triggered),
          this, qOverload<>(&MainWindow::do_actView_triggered));
  connect(ui->actView_displayProperties, qOverload<bool>(&QAction::triggered),
          this, qOverload<>(&MainWindow::do_actView_triggered));
}

MainWindow::~MainWindow() { delete ui; }

// 向某个 father 节点添加一个 type 类型子节点
FileTreeWidgetItem *MainWindow::addNewNodetoTree(QTreeWidgetItem *father,const QString &filePath,type::NodeType type) {
  QFileInfo source{filePath};
  // 检查 father 是否为 File 类型
  if (father->type() == type::NodeType::File) {
    QMessageBox::warning(
        this, "错误",
        QString{"无法向 %1 文件节点添加子节点。"}.arg(father->text(0)));
    return nullptr;
  }
  // 检查重名冲突，文件不可重名
  for (int i = 0; i < father->childCount(); i++) {
    if (father->child(i)->text(0) == source.fileName()) {
      QMessageBox::warning(
          this, "错误",
          QString{"无法添加重名节点 %1 。"}.arg(father->child(i)->text(0)));
      return nullptr;
    }
  }
  // 构造新 Item
  FileTreeWidgetItem *newItem{new FileTreeWidgetItem(father, type)};
  // 构造 Item 图标
 // QIcon nodeIcon{type == utils::NodeType::File
  //                   ? ":/fileIcons/resources/FileIcon.ico"
   //                  : ":/fileIcons/resources/FolderIcon.ico"};
  // 换算文件大小到适当单位
  QString fileSize{[](qint64 size) -> QString {
    double tmp{static_cast<double>(size)};
    QList<std::pair<QString, uint32_t>> unit{
        {"B", 2 << 0}, {"KB", 2 << 10}, {"MB", 2 << 20}, {"GB", 2 << 30}};
    int index{};
    while (tmp >= 1024.0 && index < unit.size()) {
      tmp /= 1024.0;
      ++index;
    }
    return QString{}.setNum(tmp, 'f', 2) + " " + unit[index].first;
  }(source.size())};
  // 设置 Item 各列内容
  //newItem->setIcon(0, nodeIcon);
  newItem->setText(0, source.fileName());
  newItem->setText(1, type == type::NodeType::File ? fileSize : "");
  newItem->setText(2, filePath);
  newItem->setText(3, source.lastModified().toString());
  newItem->setText(4, source.isWritable() ? "读写" : "只读");
  // 内部标记
  newItem->setText(5, "0"); // 标记文件缺失
  return newItem;
}

// 遍历目录下所有目录文件，用于添加目录时带上其所有内部文件
void MainWindow::traverseDir(QTreeWidgetItem *father, const QString &curPath) {
  QFileInfoList dirChildren{QDir{curPath}.entryInfoList()};
  // 遍历目录和文件，
  // 文件直接添加到视图树，目录先添加，再进入递归搜索
  for (int i = 2; i < dirChildren.size(); i++) {
    if (dirChildren[i].isFile()) {
      addNewNodetoTree(father, dirChildren[i].absoluteFilePath(),
                       type::NodeType::File);
    } else {
      FileTreeWidgetItem *newNode{
          addNewNodetoTree(father, dirChildren[i].absoluteFilePath(),
                           type::NodeType::Directory)};
      if (newNode != nullptr) {
        traverseDir(newNode, dirChildren[i].absoluteFilePath());
      }
    }
  }
}

// Slot 添加文件/目录
void MainWindow::do_actFile_addNode_triggered(type::NodeType type) {
  ui->compressionRateLabel->clear();
  QList<QString> path{};
  // 获取当前被选中的父节点
  QList<QTreeWidgetItem *> selected{ui->treeWidget->selectedItems()};
  QTreeWidgetItem *currentItem{
      selected.isEmpty() ? ui->treeWidget->invisibleRootItem() : selected[0]};
  // 处理 文件/路径 不同类型，得到路径
  switch (type) {
  // 可多选文件
  case type::NodeType::File:
    path = QFileDialog::getOpenFileNames(
        this, "选择文件",
        "D:/CLion/HUFCompressor/test");
    break;
  // 单选目录，并遍历目录下所有文件
  case type::NodeType::Directory:
    path.emplaceBack(QFileDialog::getExistingDirectory(
    this, "选择目录", "D:/CLion/HUFCompressor/test"));
    break;
  default:
    throw -1;
    break;
  }
  // 用户取消了选择文件操作
  if (path.isEmpty() || path[0].isEmpty()) {
    return;
  }
  // 添加所有子节点
  for (QString &pathStr : path) {
    FileTreeWidgetItem *newNode{addNewNodetoTree(currentItem, pathStr, type)};
    if (type == type::NodeType::Directory && newNode != nullptr) {
      traverseDir(newNode, path[0]);
    }
  }
}

// Slot 控制视图树需要显示的列
void MainWindow::do_actView_triggered() {
  QAction *senderObj{qobject_cast<QAction *>(sender())};
  QTreeWidget *tree{ui->treeWidget};
  // 遍历每一列，并隐藏未选中的列
  for (int i = 0; i < tree->headerItem()->columnCount(); i++) {
    if (tree->headerItem()->text(i) == senderObj->text()) {
      senderObj->isChecked() ? tree->showColumn(i) : tree->hideColumn(i);
    }
  }
}

// Slot 删除视图树中节点
void MainWindow::on_actFile_deleteFileNode_triggered() {
  ui->compressionRateLabel->clear();
  QTreeWidget *tree{ui->treeWidget};
  QList<QTreeWidgetItem *> selected{tree->selectedItems()};
  for (int i = 0; i < selected.count(); i++) {
    delete selected[i];
  }
}

// Slot 获取要添加的 HUFC 密钥文件
void MainWindow::on_toolButton_selectPath_clicked() {
  QLineEdit *pathLine{ui->lineEdit_pathDisplay};
  pathLine->setText(QFileDialog::getOpenFileName(
      this, "选择密钥文件",
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
      "HUFC 密钥文件(*.hkey)"));
}

// Slot 控制 HUFC 密钥文件选项的 Enable 属性
void MainWindow::on_checkBox_useKeytoDecompress_clicked() {
  QLineEdit *pathDisplay{ui->lineEdit_pathDisplay};
  QToolButton *pathSelectButton{ui->toolButton_selectPath};
  // 是否勾选了使用密钥
  bool flag{ui->checkBox_useKeytoDecompress->isChecked()};
  pathDisplay->setEnabled(flag);
  pathSelectButton->setEnabled(flag);
}

// Slot 处理 actionUseSeparateKeyToCompress 被触发的事件
void MainWindow::on_actionUseSeparateKeyToCompress_triggered() {
  bool isChecked = !ui->checkBox_useSeperateKeytoCompress->isChecked();
  ui->checkBox_useSeperateKeytoCompress->setChecked(isChecked);
  // 可以在这里添加更多的逻辑，比如启用或禁用相关的控件
}

// Slot 处理 actionUseKeyToDecompress 被触发的事件
void MainWindow::on_actionUseKeyToDecompress_triggered() {
  bool isChecked = !ui->checkBox_useKeytoDecompress->isChecked();
  ui->checkBox_useKeytoDecompress->setChecked(isChecked);
  QLineEdit *pathDisplay{ui->lineEdit_pathDisplay};
  QToolButton *pathSelectButton{ui->toolButton_selectPath};
  pathDisplay->setEnabled(isChecked);
  pathSelectButton->setEnabled(isChecked);
}

void MainWindow::on_actionDecompress_triggered(bool checked)
{
  on_pushButton_decompress_clicked();
}
void MainWindow::on_actionCompress_triggered(bool checked)
{
  on_pushButton_compress_clicked();
}

// Slot 执行压缩操作
void MainWindow::on_pushButton_compress_clicked() {
  ui->compressionRateLabel->clear();
  // 获取设置信息
  bool useSeperateKey{ui->checkBox_useSeperateKeytoCompress->isChecked()};
  QTreeWidget *tree{ui->treeWidget};//获取 QTreeWidget 中选中的所有文件
  QList<QTreeWidgetItem *> allSelectedFiles{tree->selectedItems()};
  if (allSelectedFiles.count() == 0)
    return;//如果没有选中任何文件，直接返回

  // 设置进度条范围
  int totalStepsPerFile = 5;  // 处理每个文件有 5 个步骤
  int totalSteps = allSelectedFiles.count() * totalStepsPerFile;
  // 显示进度条
  progressBar->setVisible(true);
  qint64 totalOriginalSize = 0;
  qint64 totalCompressedSize = 0;
  // 遍历选中的文件
  for (int i = 0; i < allSelectedFiles.count(); i++) {
    // 跳过不存在的文件
    if (allSelectedFiles[i]->text(5) == "1")
      continue;
    // 只操作文件
    if (allSelectedFiles[i]->type() == type::NodeType::File) {
      QFileInfo fileInfo{allSelectedFiles[i]->text(2)};
      QString filePath{fileInfo.absoluteFilePath()};
      QString outFilePath{filePath + ".huf"};
      QString keyFilePath{useSeperateKey ? filePath + ".hkey" : outFilePath};
      // 删除冗余文件
      if ((useSeperateKey && QFileInfo::exists(keyFilePath)) ||
          QFileInfo::exists(outFilePath)) {
        QFile::remove(keyFilePath);
        QFile::remove(outFilePath);
      }
      // 异常处理
      try {
        HUFCompressor *compressor = new HUFCompressor{{filePath}, useSeperateKey, this};
        connect(compressor, &HUFCompressor::progressUpdated, this, [this, totalSteps, i, totalStepsPerFile](int step) {
                  // 计算当前步骤在整个压缩过程中的百分比
                  int currentStep = i * totalStepsPerFile + step;
                  int progressValue = (currentStep * 100) / totalSteps;
                  progressBar->setValue(progressValue);
              });
        compressor->compressSingleFile(outFilePath, keyFilePath);

        // 获取文件大小
        totalOriginalSize += fileInfo.size();
        QFileInfo compressedFileInfo{outFilePath};
        totalCompressedSize += compressedFileInfo.size();


      } catch (int e) {
        QMessageBox::critical(this, "错误",
                              QString{"%1 "
                                      "压缩发生错误，可能是"
                                      "程序内部错误。\n错误码  %2"}
                                  .arg(filePath, QString::number(e)));
      }
    }
  }

  // 计算压缩率
  double totalCompressionRate = 100.0 * (1.0 - (double)totalCompressedSize / totalOriginalSize);
  ui->compressionRateLabel->setText(QString("压缩率: %1%").arg(totalCompressionRate, 0, 'f', 2));

  // 隐藏进度条
  progressBar->setVisible(false);
  QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "完成", "压缩操作完成", QMessageBox::NoButton, this);
  msgBox->show();
  QTimer::singleShot(2000, msgBox, &QMessageBox::accept);
}

// Slot 执行解压操作
void MainWindow::on_pushButton_decompress_clicked() {
  ui->compressionRateLabel->clear();
  bool useSeperateKey{ui->checkBox_useKeytoDecompress->isChecked()};
  QTreeWidget *tree{ui->treeWidget};
  QList<QTreeWidgetItem *> allSelectedFiles{tree->selectedItems()};
  if (allSelectedFiles.count() == 0)
    return;
  // 设置进度条范围
  int totalStepsPerFile = 5;  // 处理每个文件有 5 个步骤
  int totalSteps = allSelectedFiles.count() * totalStepsPerFile;
  // 显示进度条
  progressBar->setVisible(true);

  for (int i = 0; i < allSelectedFiles.count(); i++) {
    // 跳过不存在的文件
    if (allSelectedFiles[i]->text(5) == "1")
      continue;
    // 只操作文件
    if (allSelectedFiles[i]->type() == type::NodeType::File) {
      QFileInfo fileInfo{allSelectedFiles[i]->text(2)};
      QString filePath{fileInfo.absoluteFilePath()};
      QString keyFilePath{useSeperateKey ? ui->lineEdit_pathDisplay->text()
                                         : filePath};
      QString outFilePath{filePath.left(filePath.size() - 4)};
      if (QFileInfo::exists(outFilePath)) {
        QFile::remove(outFilePath);
      }
      // 异常处理
      try {
        HUFDecompressor decompressor{{filePath}, useSeperateKey, this};
        connect(&decompressor, &HUFDecompressor::progressUpdated, this, [this, totalSteps, i, totalStepsPerFile](int step) {
          // 计算当前步骤在整个解压过程中的百分比
          int currentStep = i * totalStepsPerFile + step;
          int progressValue = (currentStep * 100) / totalSteps;
          progressBar->setValue(progressValue);
        });

        decompressor.decompressSingleFile(outFilePath, keyFilePath);
      } catch (int e) {
        QMessageBox::critical(this, "错误",
                              QString{"%1 "
                                      "解压发生错误，可能是密钥文件不正确，或是"
                                      "程序内部错误。\n错误码  %2"}
                                  .arg(filePath, QString::number(e)));
      }
    }
  }
  // 隐藏进度条
  progressBar->setVisible(false);
  QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "完成", "解压操作完成", QMessageBox::NoButton, this);
  msgBox->show();
  QTimer::singleShot(2000, msgBox, &QMessageBox::accept);
}
