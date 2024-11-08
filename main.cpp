#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
/*压缩的文件会被保存到与原始文件相同的目录中，并且文件名会添加 .huf 扩展名
 *如果使用了单独的密钥文件，密钥文件也会被保存到相同的目录中，并且文件名会添加 .hkey 扩展名
 *
 * 解压后的文件将被保存到与原始文件相同的目录中，并且文件名将去掉 .huf 扩展名
 * 如果使用了单独的密钥文件，密钥文件路径需要在解压时指定。
 */