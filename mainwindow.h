#pragma once

#include "filetree.h"
#include "type.h"

#include <QDir>
#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QProgressBar>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  FileTreeWidgetItem *addNewNodetoTree(QTreeWidgetItem *father,
                                       const QString &filePath,
                                       type::NodeType type);

  void traverseDir(QTreeWidgetItem *father, const QString &curPath);

private slots:

  // 添加文件目录节点
  void do_actFile_addNode_triggered(type::NodeType);

  // 修改视图树可视化属性
  void do_actView_triggered();

  // 删除节点
  void on_actFile_deleteFileNode_triggered();

  // 选择密钥文件路径
  void on_toolButton_selectPath_clicked();

  // 是否使用密钥文件进行解压
  void on_checkBox_useKeytoDecompress_clicked();

  void on_actionUseSeparateKeyToCompress_triggered();
  void on_actionUseKeyToDecompress_triggered();

  void on_actionDecompress_triggered(bool checked);

  void on_actionCompress_triggered(bool checked);

  // 压缩操作按钮
  void on_pushButton_compress_clicked();

  // 解压操作按钮
  void on_pushButton_decompress_clicked();

private:
  Ui::MainWindow *ui;
  QProgressBar *progressBar;
  QLabel *compressionRateLabel;
};
