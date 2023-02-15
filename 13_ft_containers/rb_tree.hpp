#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <cstddef>
# include "iterator_tag.hpp"

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
        enum color getColor() const
        {
            return color;
        }
        void setColor(enum color color)
        {
            this->color = color;
        }
        _node *getMinNode() const
        {
            _node *node = this;
            while (node->left != NULL)
                node = node->left;
            return node;
        }
        _node *getMaxNode() const
        {
            _node *node = this;
            while (node->right != NULL)
                node = node->right;
            return node;
        }
    };

    template <typename T, typename Compare, typename Allocator>
    class rb_tree
    {
        public:
            typedef T                                                               value_type;
            typedef typename Allocator::template rebind<_node<value_type> >::other  allocator_type;
            typedef typename allocator_type::size_type                              size_type;
            typedef Compare                                                         key_compare;
            typedef ft::_node<value_type>                                           _node;
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
            bool equal(const value_type& lhs, const value_type& rhs) const
            {
                if (!_comp(lhs, rhs) && !_comp(rhs, lhs))
                    return true;
                return false;
            }
            void swapColor(_node *a, _node *b)
            {
                enum color temp;

                temp = a->getColor();
                a->setColor(b->getColor());
                b->setColor(temp);
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

                _node *temp = root->right->getMinNode();
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
                while (new_node != _root && new_node->getColor() == RED && new_node->parent->getColor() == RED) 
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
                            swapColor(parent, grandparent);
                            new_node = parent;
                        }
                    } 
                    else 
                    {
                        _node *uncle = grandparent->left;
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
                            swapColor(parent, grandparent);
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
                    _root = NULL;
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
                    while (ptr != _root && ptr->getColor() == DOUBLE_BLACK)
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
                    _root->setColor(BLACK);
                }
            }
            void removeTree(_node *node)
            {
                if (node == NULL)
                    return ;
                removeTree(node->left);
                removeTree(node->right);
                removeNode(node);
            }
        public:
            rb_tree() : _allocator(allocator_type()), _comp(key_compare()), _root(NULL), _size(0) {};
            rb_tree(allocator_type alloc, key_compare comp) : _allocator(alloc), _comp(comp), _root(NULL), _size(0) {};
            ~rb_tree()
            {
                removeTree(_root);
            }
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
                _node *node = removeBST(target);
                if (node == NULL)
                    return false;
                _size--;
                fixRemoveRBTree(node);
                return true;
            }
            void clear()
            {
                removeTree(_root);
                _root = NULL;
                _size = 0;
            }
            size_type size() const
            {
                return _size;
            }
            _node *getMinNode() const
            {
                return _root->getMinNode();
            }
            _node *getMaxNode() const
            {
                return _root->getMaxNode();
            }

            class const_iterator;

            class iterator
            {
                public:
                    typedef bidirectional_iterator_tag  iterator_category;
                    typedef T                           value_type;
                    typedef std::ptrdiff_t              difference_type;
                    typedef T*                          pointer;
                    typedef T&                          reference;
                    typedef ft::_node<value_type>       _node;
                private:
                    pointer _cur;
                    bool    _is_end;
                public:
                    iterator() : _cur(NULL), _is_end(true) {}
                    iterator(_node *node, bool is_end) : _cur(node), _is_end(is_end) {}
                    iterator(const iterator& src) : _cur(src._cur), _is_end(src._is_end) {}
                    iterator& operator=(const iterator& src)
                    {
                        _cur = src._cur;
                        _is_end = src._is_end;
                        return *this;
                    }
                    ~iterator() {}
                    reference operator*() const
                    {
                        return _cur->data;
                    }
                    pointer operator->() const 
                    {
                        return &_cur->data;
                    }
                    iterator& operator++() 
                    {
                        if (_is_end)
                            _is_end = false;
                        else if (_cur->right)
                            _cur = _cur->right->getMinNode();
                        else
                        {
                            pointer ptr = _cur;
                            while (ptr->parent && ptr->parent->right == ptr)
                                ptr = ptr->parent;
                            if (ptr->parent == NULL)
                                _is_end = true;
                            else
                                _cur = ptr->parent;
                        }
                        return *this;
                    }
                    iterator& operator--()
                    {
                        if (_is_end)
                            _is_end = false;
                        else if (_cur->left)
                            _cur = _cur->left->getMaxNode();
                        else
                        {
                            pointer ptr = _cur;
                            while (ptr->parent && ptr->parent->left == ptr)
                                ptr = ptr->parent;
                            if (ptr->parent == NULL)
                                _is_end = true;
                            else
                                _cur = ptr->parent;
                        }
                        return *this;
                    }
                    iterator operator++(int)
                    {
                        iterator tmp(*this);
                        ++*this;
                        return tmp;
                    }
                    iterator operator--(int) 
                    {
                        iterator tmp(*this);
                        --*this;
                        return tmp;
                    }
                    bool operator==(const iterator& rhs) const
                    {
                        return this->_cur == rhs._cur && this->_is_end == rhs._is_end;
                    }
                    bool operator!=(const iterator& rhs) const
                    {
                        return !(*this == rhs);
                    }
            };

            class const_iterator
            {
                public:
                    typedef bidirectional_iterator_tag  iterator_category;
                    typedef const T                     value_type;
                    typedef std::ptrdiff_t              difference_type;
                    typedef const T*                    pointer;
                    typedef const T&                    reference;
                    typedef ft::_node<value_type>       _node;
                private:
                    const pointer   _cur;
                    bool            _is_end;
                public:
                    const_iterator() : _cur(NULL), _is_end(false) {}
                    const_iterator(_node *node, bool is_end) : _cur(node), _is_end(is_end) {}
                    const_iterator(const const_iterator& src) : _cur(src._cur), _is_end(src._is_end) {}
                    const_iterator(const iterator& src) : _cur(src._cur), _is_end(src._is_end) {}
                    const_iterator& operator=(const const_iterator& src)
                    {
                        _cur = src._cur;
                        _is_end = src._is_end;
                        return *this;
                    }
                    ~const_iterator() {}
                    reference operator*() const
                    {
                        return _cur->data;
                    }
                    pointer operator->() const 
                    {
                        return &_cur->data;
                    }
                    const_iterator& operator++() 
                    {
                        if (_is_end)
                            _is_end = false;
                        else if (_cur->right)
                            _cur = _cur->right->getMinNode();
                        else
                        {
                            pointer ptr = _cur;
                            while (ptr->parent && ptr->parent->right == ptr)
                                ptr = ptr->parent;
                            if (ptr->parent == NULL)
                                _is_end = true;
                            else
                                _cur = ptr->parent;
                        }
                        return *this;
                    }
                    const_iterator& operator--()
                    {
                        if (_is_end)
                            _is_end = false;
                        else if (_cur->left)
                            _cur = _cur->left->getMaxNode();
                        else
                        {
                            pointer ptr = _cur;
                            while (ptr->parent && ptr->parent->left == ptr)
                                ptr = ptr->parent;
                            if (ptr->parent == NULL)
                                _is_end = true;
                            else
                                _cur = ptr->parent;
                        }
                        return *this;
                    }
                    const_iterator operator++(int)
                    {
                        const_iterator tmp(*this);
                        ++*this;
                        return tmp;
                    }
                    const_iterator operator--(int) 
                    {
                        const_iterator tmp(*this);
                        --*this;
                        return tmp;
                    }
                    bool operator==(const const_iterator& rhs) const
                    {
                        return this->_cur == rhs._cur && this->_is_end == rhs._is_end;
                    }
                    bool operator!=(const const_iterator& rhs) const
                    {
                        return !(*this == rhs);
                    }
            };
    };
}

#endif