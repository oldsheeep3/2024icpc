// セット (集合)
// メリット: 重複のない要素管理、要素の検索、追加、削除 (平均O(log n))

// set は一意の要素を保持するコンテナで、内部的に赤黒木を使用しています。
// 順序: 要素が常にソートされた状態で保持される。
// 操作の時間計算量: 平均して O(log n) の時間で要素の検索、挿入、削除が行われる。
// 使用例: 要素の順序が必要な場合（例えば、整数をソート順に保持したい場合）。
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30, 40, 50}; // setの宣言と初期化

    mySet.insert(60); // 要素の追加
    mySet.erase(20); // 要素の削除

    auto it = mySet.find(30); // 要素の検索
    if (it != mySet.end()) cout << "30が見つかりました。" << endl;

    if (mySet.count(50) > 0) cout << "50はセットに含まれています。" << endl; // 要素の存在チェック

    int n = 3; // 取得したい要素の位置
    auto it = mySet.begin();
    advance(it, n - 1); // イテレータをn-1回進める

    if (it != mySet.end()) {
        cout << "n番目の要素: " << *it << endl;
    } else {
        cout << "指定された位置に要素がありません。" << endl;
    }

    cout << "最小値: " << *mySet.begin() << endl; // 最小値の取得
    cout << "最大値: " << *mySet.rbegin() << endl; // 最大値の取得

    auto it_lower = mySet.lower_bound(35); // 35以上の最小の要素
    if (it_lower != mySet.end()) cout << "35以上の最小の要素: " << *it_lower << endl;

    auto it_upper = mySet.upper_bound(30); // 30より大きい最初の要素
    if (it_upper != mySet.end()) cout << "30より大きい最初の要素: " << *it_upper << endl;

    cout << "要素数: " << mySet.size() << endl; // 要素数の取得
    if (mySet.empty()) cout << "セットは空です。" << endl; // 空の確認

    for (const auto &element : mySet) cout << element << " "; // 全要素の出力
    cout << endl;
    
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    set<int> anotherSet = {1, 2, 3};
    anotherSet.swap(mySet); // 要素の交換

    mySet.clear(); // 全要素のクリア
    cout << "クリア後の要素数: " << mySet.size() << endl;

    return 0;
}

// 追加のsetの操作例
#include <iostream>
#include <set>
#include <iterator> // イテレータ用

using namespace std;

int main() {
    set<int> mySet = {10, 20, 30, 40, 50}; // setの宣言と初期化

    // 範囲削除
    auto it_start = mySet.find(20);
    auto it_end = mySet.find(40);
    mySet.erase(it_start, it_end); // 20, 30を削除

    // コピー
    set<int> copiedSet = mySet; // コピーコンストラクタ
    set<int> assignedSet;
    assignedSet = mySet; // 代入演算子

    // カスタム比較関数を使用したset
    struct DescendingOrder {
        bool operator()(int a, int b) const {
            return a > b; // 降順でソート
        }
    };

    set<int, DescendingOrder> descSet = {10, 20, 30, 40, 50};

    // イテレータを使ったアクセス
    for (auto it = descSet.begin(); it != descSet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 部分集合の判定
    set<int> subset = {10, 20};
    if (includes(mySet.begin(), mySet.end(), subset.begin(), subset.end())) {
        cout << "subsetはmySetの部分集合です。" << endl;
    }

    // 交差部分の取得
    set<int> otherSet = {30, 40, 50, 60, 70};
    set<int> intersectionSet;
    set_intersection(mySet.begin(), mySet.end(), otherSet.begin(), otherSet.end(), inserter(intersectionSet, intersectionSet.begin()));

    for (const auto &element : intersectionSet) {
        cout << element << " "; // 交差部分の要素: 40 50
    }
    cout << endl;

    // 和集合の取得
    set<int> unionSet;
    set_union(mySet.begin(), mySet.end(), otherSet.begin(), otherSet.end(), inserter(unionSet, unionSet.begin()));

    for (const auto &element : unionSet) {
        cout << element << " "; // 和集合の要素: 10 30 40 50 60 70
    }
    cout << endl;

    // 差集合の取得
    set<int> differenceSet;
    set_difference(mySet.begin(), mySet.end(), otherSet.begin(), otherSet.end(), inserter(differenceSet, differenceSet.begin()));

    for (const auto &element : differenceSet) {
        cout << element << " "; // 差集合の要素: 10
    }
    cout << endl;

    return 0;
}


// std::multiset
#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms;

    // 要素の挿入
    ms.insert(3);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);

    std::cout << "Elements after insertion: ";
    for (int value : ms) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // 要素の削除
    ms.erase(ms.find(2));  // 最初の2を削除
    ms.erase(ms.find(1));  // 1を削除

    std::cout << "Elements after deletion: ";
    for (int value : ms) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

// ループの中で要素を削除する際にsegmentation faultが発生する理由の一つは、イテレータが無効化されることです。
// イテレータを使ってコンテナを操作している最中に、そのイテレータが指している要素を削除すると、イテレータが無効になり、次の操作でアクセス違反が発生する可能性があります。
// これを避けるためには、要素を削除した後にイテレータを正しく更新する必要があります。
// std::multisetでは、削除した要素の次の要素を指すイテレータを受け取ることができるため、これを利用して正しくイテレータを更新できます。
#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms = {1, 2, 3, 2, 4, 5};

    for (auto it = ms.begin(); it != ms.end(); ) {
        if (*it == 2) {
            // イテレータが無効化されないように削除後に次の要素を取得
            it = ms.erase(it);
        } else {
            ++it;
        }
    }

    std::cout << "Elements after deletion: ";
    for (int value : ms) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}



// ハッシュセット (unordered_set)
// メリット: 重複のない要素管理、要素の検索、追加、削除 (平均O(1))

// unordered_set はハッシュテーブルを使用するコンテナです。
// 順序: 要素は順序を持たない。
// 操作の時間計算量: 平均して O(1) の時間で要素の検索、挿入、削除が行われる。
// 使用例: 要素の順序が不要で、効率的な検索、挿入、削除が必要な場合。
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // unordered_setの宣言
    unordered_set<int> uset;

    // 要素の追加
    uset.insert(1);
    uset.insert(2);

    // 要素の検索
    if (uset.find(1) != uset.end()) {
        cout << "1 found in the set" << endl; // 1 found in the set
    }

    // 要素の削除
    uset.erase(2);

    // 全ての要素を出力
    for (int elem : uset) {
        cout << elem << endl; // 1
    }
    // 順序は保証されない

    return 0;
}