#pragma once
#include <memory>

template <typename Type>
class SegmentTree {
private:
	struct Node {
		int min;
		int max;
		Type data;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;

		Node(int min, int max)
			: min(min)
			, max(max)
		{}
	};

	std::shared_ptr<Node> m_root;
	std::weak_ptr<Node> m_zero;

	std::shared_ptr<Node> createNode(int min, int max)
	{
		auto ptr = std::make_shared<Node>(min, max);
		if (min != max) {
			int mid = min + (max - min) / 2;
			ptr->left = createNode(min, mid);
			ptr->right = createNode(mid + 1, max);
		}
		return ptr;
	}

public:
	explicit SegmentTree(int size)
	{
		m_root = createNode(0, size - 1);
		auto ptr = m_root;
		while (ptr->left != nullptr) {
			ptr = ptr->left;
		}
		m_zero = ptr;
	}

	void insert(int index, const Type& obj)
	{
		auto current = m_root;
		
		for (;;) {
			if (obj > current->data) {
				current->data = obj;
			}
		
			if (current->left == nullptr /*|| current->m_right == nullptr*/) {
				return;
			}
			else if (index < current->right->min) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	}

	const Type& max(int index) const
	{
		auto current = m_root;

		// ptr to element 0
		auto best = m_zero.lock();
		
		for (;;) {
			if (index == current->max) {
				if (current->data > best->data) {
					best = current;
				}
				return best->data;
			}
			else if (index < current->right->min) {
				current = current->left;
			}
			else {
				if (current->left->data > best->data) {
					best = current->left;
				}
				current = current->right;
			}
		}
	}

	const Type& max() const
	{
		return m_root->data;
	}
};