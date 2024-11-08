/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actFile_addDir;
    QAction *actFile_addFile;
    QAction *act_Exit;
    QAction *actView_displayIcons;
    QAction *actView_displayName;
    QAction *actView_displaySize;
    QAction *actView_displayPath;
    QAction *actView_displayEditTime;
    QAction *actView_displayProperties;
    QAction *actTool_about;
    QAction *actFile_deleteFileNode;
    QAction *actionUseSeparateKeyToCompress;
    QAction *actionUseKeyToDecompress;
    QAction *actionCompress;
    QAction *actionDecompress;
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QCheckBox *checkBox_useSeperateKeytoCompress;
    QToolButton *toolButton_selectPath;
    QLineEdit *lineEdit_pathDisplay;
    QCheckBox *checkBox_useKeytoDecompress;
    QPushButton *pushButton_decompress;
    QPushButton *pushButton_compress;
    QProgressBar *progressBar;
    QLabel *compressionRateLabel;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_V;
    QMenu *menu_T;
    QMenu *menu;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(821, 633);
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/title.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        actFile_addDir = new QAction(MainWindow);
        actFile_addDir->setObjectName("actFile_addDir");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/lenovo/Desktop/image/directory.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_addDir->setIcon(icon1);
        QFont font;
        font.setPointSize(10);
        actFile_addDir->setFont(font);
        actFile_addFile = new QAction(MainWindow);
        actFile_addFile->setObjectName("actFile_addFile");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("C:/Users/lenovo/Desktop/image/file.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_addFile->setIcon(icon2);
        act_Exit = new QAction(MainWindow);
        act_Exit->setObjectName("act_Exit");
        actView_displayIcons = new QAction(MainWindow);
        actView_displayIcons->setObjectName("actView_displayIcons");
        actView_displayName = new QAction(MainWindow);
        actView_displayName->setObjectName("actView_displayName");
        actView_displayName->setCheckable(true);
        actView_displayName->setChecked(true);
        actView_displayName->setFont(font);
        actView_displaySize = new QAction(MainWindow);
        actView_displaySize->setObjectName("actView_displaySize");
        actView_displaySize->setCheckable(true);
        actView_displaySize->setChecked(true);
        actView_displayPath = new QAction(MainWindow);
        actView_displayPath->setObjectName("actView_displayPath");
        actView_displayPath->setCheckable(true);
        actView_displayPath->setChecked(true);
        actView_displayEditTime = new QAction(MainWindow);
        actView_displayEditTime->setObjectName("actView_displayEditTime");
        actView_displayEditTime->setCheckable(true);
        actView_displayEditTime->setChecked(true);
        actView_displayProperties = new QAction(MainWindow);
        actView_displayProperties->setObjectName("actView_displayProperties");
        actView_displayProperties->setCheckable(true);
        actView_displayProperties->setChecked(true);
        actTool_about = new QAction(MainWindow);
        actTool_about->setObjectName("actTool_about");
        actFile_deleteFileNode = new QAction(MainWindow);
        actFile_deleteFileNode->setObjectName("actFile_deleteFileNode");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("C:/Users/lenovo/Desktop/image/delete.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actFile_deleteFileNode->setIcon(icon3);
        actionUseSeparateKeyToCompress = new QAction(MainWindow);
        actionUseSeparateKeyToCompress->setObjectName("actionUseSeparateKeyToCompress");
        actionUseSeparateKeyToCompress->setCheckable(true);
        actionUseSeparateKeyToCompress->setChecked(false);
        actionUseSeparateKeyToCompress->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("image/en.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUseSeparateKeyToCompress->setIcon(icon4);
        actionUseKeyToDecompress = new QAction(MainWindow);
        actionUseKeyToDecompress->setObjectName("actionUseKeyToDecompress");
        actionUseKeyToDecompress->setCheckable(true);
        actionUseKeyToDecompress->setChecked(false);
        actionUseKeyToDecompress->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("image/de.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUseKeyToDecompress->setIcon(icon5);
        actionCompress = new QAction(MainWindow);
        actionCompress->setObjectName("actionCompress");
        actionCompress->setCheckable(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("C:/Users/lenovo/Desktop/image/encode.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompress->setIcon(icon6);
        actionCompress->setMenuRole(QAction::NoRole);
        actionDecompress = new QAction(MainWindow);
        actionDecompress->setObjectName("actionDecompress");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("C:/Users/lenovo/Desktop/image/decode.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDecompress->setIcon(icon7);
        actionDecompress->setMenuRole(QAction::NoRole);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        treeWidget = new QTreeWidget(centralWidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(0, 30, 821, 431));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setFont(font);
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setFrameShadow(QFrame::Plain);
        treeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeWidget->setSortingEnabled(true);
        treeWidget->setAnimated(true);
        treeWidget->setHeaderHidden(false);
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setDefaultSectionSize(175);
        checkBox_useSeperateKeytoCompress = new QCheckBox(centralWidget);
        checkBox_useSeperateKeytoCompress->setObjectName("checkBox_useSeperateKeytoCompress");
        checkBox_useSeperateKeytoCompress->setGeometry(QRect(360, 470, 51, 20));
        toolButton_selectPath = new QToolButton(centralWidget);
        toolButton_selectPath->setObjectName("toolButton_selectPath");
        toolButton_selectPath->setEnabled(false);
        toolButton_selectPath->setGeometry(QRect(680, 490, 24, 22));
        lineEdit_pathDisplay = new QLineEdit(centralWidget);
        lineEdit_pathDisplay->setObjectName("lineEdit_pathDisplay");
        lineEdit_pathDisplay->setEnabled(false);
        lineEdit_pathDisplay->setGeometry(QRect(560, 490, 111, 21));
        lineEdit_pathDisplay->setReadOnly(true);
        checkBox_useKeytoDecompress = new QCheckBox(centralWidget);
        checkBox_useKeytoDecompress->setObjectName("checkBox_useKeytoDecompress");
        checkBox_useKeytoDecompress->setGeometry(QRect(360, 500, 51, 20));
        pushButton_decompress = new QPushButton(centralWidget);
        pushButton_decompress->setObjectName("pushButton_decompress");
        pushButton_decompress->setGeometry(QRect(420, 470, 101, 50));
        pushButton_decompress->setMinimumSize(QSize(50, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213")});
        font1.setPointSize(12);
        pushButton_decompress->setFont(font1);
        pushButton_decompress->setStyleSheet(QString::fromUtf8(""));
        pushButton_decompress->setIcon(icon7);
        pushButton_decompress->setIconSize(QSize(50, 50));
        pushButton_compress = new QPushButton(centralWidget);
        pushButton_compress->setObjectName("pushButton_compress");
        pushButton_compress->setEnabled(true);
        pushButton_compress->setGeometry(QRect(230, 470, 101, 50));
        pushButton_compress->setMinimumSize(QSize(50, 50));
        pushButton_compress->setFont(font1);
        pushButton_compress->setLayoutDirection(Qt::LeftToRight);
        pushButton_compress->setAutoFillBackground(false);
        pushButton_compress->setStyleSheet(QString::fromUtf8(""));
        pushButton_compress->setIcon(icon6);
        pushButton_compress->setIconSize(QSize(50, 50));
        pushButton_compress->setCheckable(false);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(30, 530, 781, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        compressionRateLabel = new QLabel(centralWidget);
        compressionRateLabel->setObjectName("compressionRateLabel");
        compressionRateLabel->setGeometry(QRect(40, 470, 121, 41));
        compressionRateLabel->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 431, 20));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setUnderline(false);
        label->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 821, 22));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        menu_V = new QMenu(menubar);
        menu_V->setObjectName("menu_V");
        menu_T = new QMenu(menubar);
        menu_T->setObjectName("menu_T");
        menu = new QMenu(menu_T);
        menu->setObjectName("menu");
        menu->setFont(font);
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setOrientation(Qt::Horizontal);
        toolBar->setIconSize(QSize(53, 40));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_V->menuAction());
        menubar->addAction(menu_T->menuAction());
        menu_F->addAction(actFile_addDir);
        menu_F->addAction(actFile_addFile);
        menu_F->addAction(actFile_deleteFileNode);
        menu_F->addSeparator();
        menu_V->addAction(actView_displayName);
        menu_V->addAction(actView_displaySize);
        menu_V->addAction(actView_displayPath);
        menu_V->addAction(actView_displayEditTime);
        menu_V->addAction(actView_displayProperties);
        menu_V->addSeparator();
        menu_T->addAction(menu->menuAction());
        menu_T->addSeparator();
        menu->addAction(actionUseSeparateKeyToCompress);
        menu->addAction(actionUseKeyToDecompress);
        toolBar->addSeparator();
        toolBar->addAction(actFile_addDir);
        toolBar->addSeparator();
        toolBar->addAction(actFile_addFile);
        toolBar->addSeparator();
        toolBar->addAction(actFile_deleteFileNode);
        toolBar->addSeparator();
        toolBar->addAction(actionCompress);
        toolBar->addSeparator();
        toolBar->addAction(actionDecompress);
        toolBar->addSeparator();
        toolBar->addAction(actionUseSeparateKeyToCompress);
        toolBar->addAction(actionUseKeyToDecompress);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HFU\345\216\213\347\274\251\350\247\243\345\216\213", nullptr));
        actFile_addDir->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        actFile_addDir->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actFile_addDir->setStatusTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225\345\210\260\350\247\206\345\233\276\346\211\200\351\200\211\347\233\256\345\275\225\344\270\213", nullptr));
#endif // QT_CONFIG(statustip)
        actFile_addFile->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        actFile_addFile->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        actFile_addFile->setStatusTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266\345\210\260\350\247\206\345\233\276\346\211\200\351\200\211\347\233\256\345\275\225\346\240\221\344\270\213", nullptr));
#endif // QT_CONFIG(statustip)
        act_Exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        act_Exit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        act_Exit->setStatusTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(statustip)
        actView_displayIcons->setText(QCoreApplication::translate("MainWindow", "\345\233\276\346\240\207", nullptr));
        actView_displayName->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        actView_displaySize->setText(QCoreApplication::translate("MainWindow", "\345\244\247\345\260\217", nullptr));
        actView_displayPath->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        actView_displayEditTime->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        actView_displayProperties->setText(QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247", nullptr));
        actTool_about->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actFile_deleteFileNode->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
        actionUseSeparateKeyToCompress->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206", nullptr));
#if QT_CONFIG(tooltip)
        actionUseSeparateKeyToCompress->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\347\213\254\347\253\213\345\257\206\351\222\245\345\216\213\347\274\251", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUseKeyToDecompress->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\257\206", nullptr));
#if QT_CONFIG(tooltip)
        actionUseKeyToDecompress->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\345\257\206\351\222\245\350\247\243\345\216\213", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCompress->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
#if QT_CONFIG(tooltip)
        actionCompress->setToolTip(QCoreApplication::translate("MainWindow", "\345\216\213\347\274\251", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDecompress->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
#if QT_CONFIG(tooltip)
        actionDecompress->setToolTip(QCoreApplication::translate("MainWindow", "\350\247\243\345\216\213", nullptr));
#endif // QT_CONFIG(tooltip)
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\345\244\247\345\260\217", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_useSeperateKeytoCompress->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\206\347\246\273 Huffman \347\274\226\347\240\201", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        checkBox_useSeperateKeytoCompress->setStatusTip(QCoreApplication::translate("MainWindow", "\344\270\215\345\206\231\345\205\245 Huffman \344\277\241\346\201\257\345\210\260\346\226\207\344\273\266\344\270\255\357\274\214\345\210\206\347\246\273\344\275\234\344\270\272\345\257\206\351\222\245\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(statustip)
        checkBox_useSeperateKeytoCompress->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206", nullptr));
        toolButton_selectPath->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lineEdit_pathDisplay->setText(QString());
#if QT_CONFIG(tooltip)
        checkBox_useKeytoDecompress->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240 Huffman \346\240\221\345\257\206\351\222\245\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        checkBox_useKeytoDecompress->setStatusTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\257\206\351\222\245\346\226\207\344\273\266\344\275\234\350\277\233\350\241\214\350\247\243\347\240\201", nullptr));
#endif // QT_CONFIG(statustip)
        checkBox_useKeytoDecompress->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\257\206", nullptr));
        pushButton_decompress->setText(QCoreApplication::translate("MainWindow", " \350\247\243 \345\216\213", nullptr));
        pushButton_compress->setText(QCoreApplication::translate("MainWindow", "  \345\216\213 \347\274\251", nullptr));
        compressionRateLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "| \346\267\273\345\212\240\347\233\256\345\275\225\360\237\221\206 | \346\267\273\345\212\240\346\226\207\344\273\266\360\237\221\206 |   \345\210\240   \351\231\244 \360\237\221\206  |   \345\216\213  \347\274\251 \360\237\221\206  |   \350\247\243   \345\216\213 \360\237\221\206  |", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\357\274\210F\357\274\211", nullptr));
        menu_V->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\357\274\210V\357\274\211", nullptr));
        menu_T->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267(T)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
