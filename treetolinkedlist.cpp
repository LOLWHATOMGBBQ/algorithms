#include <bits/stdc++.h>
// USES O(1) auxiliary space!!

using namespace std;

struct Node {
	int name;

	Node* next_in_linked_list = nullptr;
	vector<Node*> children;
};

void create_linked_list(Node* head) {
	Node* ptr_beg = head, ptr_end = head, cur_node = head;

	do {
		head = ptr_beg;
		// Skip the empty bad kiddos
		for (; head->children.empty() && head->next_in_linked_list; head = head->next_in_linked_list);

		// So this means it's not the end
		if (!head->children.empty()) {
			ptr_beg = head->children.front();
			Node * temp_end = ptr_beg;
			// Iterate over the row
			do {
				for (Node* next : head->children) {
					cur->next_in_linked_list = next;
					cur = cur->next_in_linked_list;

					// Make it the last one in the row
					temp_end = next;
				}
				head = head->next_in_linked_list;
			} while (head != ptr_end)
			ptr_end = temp_end;
		}
	} while (head->next_in_linked_list);
}
