#include "hufBase.h"
#include <QDebug>
#include <QHash>
#include <queue>

// 重载大于运算符，根据节点的频率和深度进行排序
bool HuffmanNode::operator>(const HuffmanNode &other) const {
  if (this->frequency == other.frequency) {//频率相同的情况下，深度较小的节点优先级更高
    return this->depth > other.depth;
  }
  return this->frequency > other.frequency;//确保频率较低的节点优先级更高
}

// 重载等于运算符，用于比较两个比特数组是否相等
bool HuffmanCode::BitArray::operator==(const BitArray &other) const {
  for (int i = 0; i < 3; i++) {
    if (this->arr[i] != other.arr[i]) {
      return false;
    }
  }
  return true;
}

// 用于向当前的霍夫曼编码中追加一个比特（0 或 1）的函数
HuffmanCode HuffmanCode::append(bool bit) {
  if (bit) {
    this->huf.arr[this->bitLength / 64] |= (1 << bitLength % 64);
  } else {
    this->huf.arr[this->bitLength / 64] &= ~(1 << bitLength % 64);
  }
  ++bitLength;
  return *this;
}

// 计算 HuffmanCode 对象的哈希值的函数
size_t qHash(const HuffmanCode &code, size_t seed) {
  size_t ret{};
  for (int i = 0; i < 4; i++) {
    ret ^= code.huf.arr[i];
  }
  return ::qHash(ret, seed);
}

//重载等于运算符，用于比较两个 HuffmanCode 对象是否相等
bool HuffmanCode::operator==(const HuffmanCode &other) const {
  return this->bitLength == other.bitLength && this->huf == other.huf;
}

// 实现 HuffmanBase Class
HuffmanBase::HuffmanBase(QObject *parent) : QObject{parent} {}

// 构造 Huffman 树
void HuffmanBase::buildTree(const QList<std::pair<ByteSize, FreqSize>> input) {
  // 小根堆
  if (lock1)
    throw 901;
  std::priority_queue<HuffmanNode, std::vector<HuffmanNode>,
                      std::greater<HuffmanNode>>
      nodeQueue{};//创建一个小根堆 nodeQueue，用于存储霍夫曼节点

  // 初始化 nodeQueue 和 Huffman 树，
  // 将每个叶子节点加入 Huffman 树和 nodeQueue
  for (int i = 0; i < input.size(); i++) {
    ByteSize byteData{input[i].first};
    FreqSize frequency{input[i].second};
    // 跳过词频为 0 的 Byte 数据
    if (frequency == 0)
      continue;
    //创建一个新的 HuffmanNode 对象，初始化其深度、字节数据、频率、节点编号和是否为叶子节点。
    HuffmanNode node{1, byteData, frequency, treeNodeCount++, 1};
    //将新创建的节点加入小根堆
    nodeQueue.emplace(node);
    // 将新创建的节点加入霍夫曼树的容器中
    tree.emplaceBack(node);
  }

  // 最小词频节点合并，得到新的父节点，其词频为两个子节点之和，
  // 按词频小，树深度小的优先顺序合并树，
  // 最后得到一棵最优二叉树，即所需 Huffman 树
  while (nodeQueue.size() > 1) {
    HuffmanNode n1{nodeQueue.top()};
    nodeQueue.pop();
    HuffmanNode n2{nodeQueue.top()};
    nodeQueue.pop();
    // 构造新节点
    HuffmanNode newFather{0, 0, n1.frequency + n2.frequency, treeNodeCount++,
                          std::max(n1.depth, n2.depth) + 1};
    // 分配边权，左子节点分配边权 0，构造 Huffman 编码时使用
    if (n1.frequency < n2.frequency) {
      newFather.leftChildIndex = n1.curIndex;
      newFather.rightChildIndex = n2.curIndex;
    } else {
      newFather.leftChildIndex = n2.curIndex;
      newFather.rightChildIndex = n1.curIndex;
    }
    nodeQueue.emplace(newFather);
    tree.emplaceBack(newFather);
  }
  lock1 = true;//表示霍夫曼树已经构建完成
}

// 遍历 Huffman 树
void HuffmanBase::traverse(NodeCntSize curIndex, HuffmanCode curHufCode) {
  HuffmanNode *curNode{&tree[curIndex]};
  // 到达叶子节点，即建立字节数据 与 HuffmanCode 的双向映射
  if (curNode->isLeaveNode) {
    byteToHufCode[curNode->byteCode] = curHufCode;
    hufCodeToByte[curHufCode] = curNode->byteCode;
  } else {
    HuffmanCode left{curHufCode};
    HuffmanCode right{curHufCode};
    left.append(0);
    right.append(1);
    traverse(curNode->leftChildIndex, left);
    traverse(curNode->rightChildIndex, right);
  }
}

// 开始建立 HashMap
void HuffmanBase::buildHashMap() {
  if (!lock1 || lock2)
    throw 902;
  traverse(treeNodeCount - 1, HuffmanCode{});
  lock2 = true;
}
