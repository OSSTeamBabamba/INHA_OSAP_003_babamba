#include <iostream>
#include <string>
#include <utility>

#include "avl_tree_set_adapter.h"
#include "cse_set.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_iter;
  cin >> test_iter;

  for (int i = 0; i < test_iter; i++) {
    Set* s = new AVLTreeSetAdapter();

    int command_iter;
    cin >> command_iter;

    for (int j = 0; j < command_iter; j++) {
      string command_word;
      cin >> command_word;
      if (command_word == "empty") {
        cout << s->Empty() << '\n';
      } else if (command_word == "size") {
        cout << s->Size() << '\n';

      } else {
        int key;
        cin >> key;

        if (command_word == "insert") {
          cout << s->Insert(key) << '\n';

        } else if (command_word == "erase") {
          cout << s->Erase(key) << '\n';
        } else if (command_word == "maximum") {
          pair<int, int> max = s->Maximum(key);
          cout << max.second << " " << max.first << '\n';
        } else if (command_word == "minimum") {
          pair<int, int> min = s->Minimum(key);
          cout << min.second << " " << min.first << '\n';
        } else if (command_word == "find") {
          int findKeyDepth = s->Find(key);
          if (findKeyDepth == -1) {
            cout << 0 << '\n';
          } else {
            cout << findKeyDepth << '\n';
          }
        }

        else if (command_word == "rank") {
          pair<int, int> rank_info = s->Rank(key);
          if (rank_info.first == -1) {
            cout << 0 << '\n';
          } else {
            cout << rank_info.first << " " << rank_info.second << '\n';
          }
        }
      }
    }
  }

  return 0;
}
