#ifndef RB_TREE_HPP
# define RB_TREE_HPP

namespace ft
{
    enum color {RED, BLACK, DOUBLE_BLACK};

    template <typename T>
    struct _node
    {
        typedef T       value_type;

        value_type      data;
        enum color      color;
        _node           *left;
        _node           *right;
        _node           *parent;

        _node() : data(value_type()), color(BLACK), left(NULL), right(NULL), parent(NULL) {}
        _node(value_type data) : data(data), color(RED), left(NULL), right(NULL), parent(NULL) {}
    };

    template <typename T, typename Compare, typename Allocator>
    class rb_tree
    {
        public:
            typedef T                                                       value_type;
            typedef typename Allocator::template rebind<node>::other        allocator_type;
            typedef typename allocator_type::size_type                      size_type;
            typedef Compare                                                 key_compare;
            typedef _node<value_type>                                       _node;
        private:
            allocator_type  _allocator;
            key_compare     _comp;
            _node          *_root;
            size_type       _size;
        private:
            _node *createNode(const value_type& data) const
            {
                _node   *node = _allocator.allocate(1);
                _allocator.construct(node, _node(data));
                return node;
            }
            void removeNode(_node *node)
            {
                _allocator.destroy(node);
                _allocator.deallocate(node, 1);
            }
            void removeLeftSubTree(_node *sub_tree)
            {
                removeNode(sub_tree->left);
                sub_tree->left = NULL;
            }
            void removeRightSubTree(_node *sub_tree)
            {
                removeNode(sub_tree->right);
                sub_tree->right = NULL;
            }
            bool equal(const value_type& lhs, const value_type& rhs) const
            {
                if (!_comp(lhs, rhs) && !_comp(rhs, lhs))
                    return true;
                return false;
            }
            _node *minValueNode(_node *node) const
            {
                while (node->left != null)
                    node = node->left;
                return node;
            }
            _node *insertBST(_node *new_node)
            {
                _node *cur = _root;
                while (1)
                {
                    if (equal(cur->data, new_node->data))
                        return NULL;
                    if (_comp(new_node->data, cur->data))
                    {
                        if (cur->left == NULL)
                        {
                            cur->left = new_node;
                            cur->left->parent = cur;
                            break ;
                        }
                        cur = cur->left;
                    }
                    else
                    {
                        if (cur->right == NULL)
                        {
                            cur->right = new_node;
                            cur->right->parent = cur;
                            break ;
                        }
                        cur = cur->right;
                    }
                }
                return new_node;
            }
            _node *removeBST(_node *root, const value_type &data)
            {
                if (root == NULL)
                    return NULL;

                if (data < root->data)
                    return removeBST(root->left, data);

                if (data > root->data)
                    return removeBST(root->right, data);

                if (root->left == NULL || root->right == NULL)
                    return root;

                _node *temp = minValueNode(root->right);
                root->data = temp->data;
                return removeBST(root->right, temp->data);
            }
            void rotateLeft(_node *node)
            {
                _node *right_child = node->right;
                node->right = right_child->left;

                if (node->right != NULL)
                    node->right->parent = node;

                right_child->parent = node->parent;

                if (node->parent == NULL)
                    _root = right_child;
                else if (node == node->parent->left)
                    node->parent->left = right_child;
                else
                    node->parent->right = right_child;

                right_child->left = node;
                node->parent = right_child;
            }
            void rotateRight(_node *node)
            {
                _node *left_child = node->left;
                node->left = left_child->right;

                if (node->left != NULL)
                    node->left->parent = node;

                left_child->parent = node->parent;

                if (node->parent == NULL)
                    _root = left_child;
                else if (node == node->parent->left)
                    node->parent->left = left_child;
                else
                    node->parent->right = left_child;

                left_child->right = node;
                node->parent = left_child;
            }
            void fixInsertRBTree(_node *new_node)
            {
                _node *parent = NULL;
                _node *grandparent = NULL;
                while (new_node != root && new_node->getColor() == RED && new_node->parent->getColor() == RED) 
                {
                    parent = new_node->parent;
                    grandparent = parent->parent;
                    if (parent == grandparent->left)
                    {
                        _node *uncle = grandparent->right;
                        if (uncle->getColor() == RED) 
                        {
                            uncle->setColor(BLACK);
                            parent->setColor(BLACK);
                            grandparent->setColor(RED);
                            new_node = grandparent;
                        }
                        else 
                        {
                            if (new_node == parent->right)
                            {
                                rotateLeft(parent);
                                new_node = parent;
                                parent = new_node->parent;
                            }
                            rotateRight(grandparent);
                            swap(parent->getColor(), grandparent->getColor());
                            new_node = parent;
                        }
                    } 
                    else 
                    {
                        Node *uncle = grandparent->left;
                        if (uncle->getColor() == RED)
                        {
                            uncle->setColor(BLACK);
                            parent->setColor(BLACK);
                            grandparent->setColor(RED);
                            new_node = grandparent;
                        }
                        else
                        {
                            if (new_node == parent->left)
                            {
                                rotateRight(parent);
                                new_node = parent;
                                parent = new_node->parent;
                            }
                            rotateLeft(grandparent);
                            swap(parent->getColor(), grandparent->getColor());
                            new_node = parent;
                        }
                    }
                }
                _root->setColor(BLACK);
            }
            void fixRemoveRBTree(_node *node)
            {
                if (node == NULL)
                    return ;

                if (node == _root)
                {
                    root = NULL;
                    return ;
                }

                if (node->getColor() == RED || node->left->getColor() == RED || node->right->getColor() == RED)
                {
                    _node *child = node->left != NULL ? node->left : node->right;

                    if (node == node->parent->left)
                    {
                        node->parent->left = child;
                        if (child != NULL)
                            child->parent = node->parent;
                        child->setColor(BLACK);
                        removeNode(node);
                    } 
                    else 
                    {
                        node->parent->right = child;
                        if (child != NULL)
                            child->parent = node->parent;
                        child->setColor(BLACK);
                        removeNode(node);
                    }
                } 
                else 
                {
                    _node *sibling = NULL;
                    _node *parent = NULL;
                    _node *ptr = node;
                    ptr->setColor(DOUBLE_BLACK);
                    while (ptr != root && ptr->getColor() == DOUBLE_BLACK)
                    {
                        parent = ptr->parent;
                        if (ptr == parent->left)
                        {
                            sibling = parent->right;
                            if (sibling->getColor() == RED)
                            {
                                sibling->setColor(BLACK);
                                parent->setColor(RED);
                                rotateLeft(parent);
                            } 
                            else
                            {
                                if (sibling->left->getColor() == BLACK && sibling->right->getColor() == BLACK)
                                {
                                    sibling->setColor(RED);
                                    if (parent->getColor() == RED)
                                        parent->setColor(BLACK);
                                    else
                                        parent->setColor(DOUBLE_BLACK);
                                    ptr = parent;
                                }
                                else
                                {
                                    if (sibling->right->getColor() == BLACK)
                                    {
                                        sibling->left->setColor(BLACK);
                                        sibling->setColor(RED);
                                        rotateRight(sibling);
                                        sibling = parent->right;
                                    }
                                    sibling->setColor(parent->color);
                                    parent->setColor(BLACK);
                                    sibling->right->setColor(BLACK);
                                    rotateLeft(parent);
                                    break ;
                                }
                            }
                        } 
                        else
                        {
                            sibling = parent->left;
                            if (sibling->getColor() == RED)
                            {
                                sibling->setColor(BLACK);
                                parent->setColor(RED);
                                rotateRight(parent);
                            } 
                            else
                            {
                                if (sibling->left->getColor() == BLACK && sibling->right->getColor() == BLACK)
                                {
                                    sibling->setColor(RED);
                                    if (parent->getColor() == RED)
                                        parent->setColor(BLACK);
                                    else
                                        parent->setColor(DOUBLE_BLACK);
                                    ptr = parent;
                                }
                                else
                                {
                                    if (sibling->left->getColor() == BLACK)
                                    {
                                        sibling->right->setColor(BLACK);
                                        sibling->setColor(RED);
                                        rotateLeft(sibling);
                                        sibling = parent->left;
                                    }
                                    sibling->setColor(parent->color);
                                    parent->setColor(BLACK);
                                    sibling->left->setColor(BLACK);
                                    rotateRight(parent);
                                    break ;
                                }
                            }
                        }
                    }
                    if (node == node->parent->left)
                        node->parent->left = NULL;
                    else
                        node->parent->right = NULL;
                    removeNode(node);
                    root->setColor(BLACK);
                }
            }
        public:
            rb_tree() : _allocator(allocator_type()), _comp(key_compare()), _root(NULL), _size(0) {};
            _node *insert(value_type data)
            {
                _node *new_node = createNode(data);
                if (_root == NULL)
                {
                    _root = new_node;
                    return _root;
                }
                if (insertBST(new_node) == NULL)
                {
                    removeNode(new_node);
                    return NULL;
                }
                _size++;
                fixInsertRBTree(new_node);
                return new_node;
            }
            bool remove(const value_type& target)
            {
                _node *node = removeBST(data);
                if (node == NULL)
                    return false;
                fixRemoveRBTree(node);
                return true;
            }
    };
}

#endif