#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <cstddef>
# include <memory>
# include "iterator_tag.hpp"

namespace ft
{
    enum color {RED, BLACK};

    template <typename T>
    struct _node
    {
        typedef T                   value_type;
        typedef _node<value_type>   _Node;
        typedef _node<value_type>*  _Nodeptr;

        value_type      data;
        enum color      color;
        _Nodeptr        left;
        _Nodeptr        right;
        _Nodeptr        parent;

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
        void changeColor()
        {
            color = color == RED ? BLACK : RED;
        }
        value_type getData() const
        {
            return data;
        }
        _Nodeptr getMinNode()
        {
            _Nodeptr node = this;
            while (node->left != NULL)
                node = node->left;
            return node;
        }
        _Nodeptr getMaxNode()
        {
            _Nodeptr node = this;
            while (node->right != NULL)
                node = node->right;
            return node;
        }
        _Nodeptr getUncle() const
        {
            _Nodeptr parent = this->parent;
            if (parent == NULL || parent->parent == NULL)
                return NULL;
            return parent->isLeftChild() ? parent->parent->right : parent->parent->left;
        }
        bool isLeftChild()
        {
            if (this->parent == NULL || this == this->parent->right)
                return false;
            return true;
        }
        bool isRightChild()
        {
            if (this->parent == NULL || this == this->parent->left)
                return false;
            return true;
        }
    };

    template <typename T>
    void swap(T& a, T& b)
    {
        T temp;

        temp = a;
        a = b;
        b = temp;
    }

    template <typename T, typename Compare, typename Allocator>
    class rb_tree
    {
        public:
            typedef ft::_node<T>                                                    _Node;
            typedef ft::_node<T>*                                                   _Nodeptr;
            typedef T                                                               value_type;
            typedef typename Allocator::template rebind<_Node>::other               allocator_type;
            typedef typename allocator_type::size_type                              size_type;
            typedef Compare                                                         key_compare;
        private:
            allocator_type  _allocator;
            key_compare     _comp;
            _Nodeptr        _root;
            size_type       _size;
        private:
            _Nodeptr createNode(const value_type& data)
            {
                _Nodeptr node = _allocator.allocate(1);
                _allocator.construct(node, _Node(data));
                return node;
            }
            void removeNode(_Nodeptr node)
            {
                _allocator.destroy(node);
                _allocator.deallocate(node, 1);
            }
            bool equal(const value_type& lhs, const value_type& rhs)
            {
                if (!_comp(lhs, rhs) && !_comp(rhs, lhs))
                    return true;
                return false;
            }
            bool insertBST(_Nodeptr new_node)
            {
                if (_root == NULL)
                {
                    _root = new_node;
                    _root->setColor(BLACK);
                    return true;
                }

                _Nodeptr cur = _root;
                while (1)
                {
                    if (this->equal(cur->data, new_node->data))
                        return false;
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
                fixInsertRBTree(new_node);
                return true;
            }
            _Nodeptr removeBST(const value_type &target)
            {
                _Nodeptr    del = get(target);
                
                if (del == NULL)
                    return NULL;

                _Nodeptr    dummy;
                _Nodeptr    replace;
                _Node       nil;
                enum color  remove_color;

                dummy = _allocator.allocate(1);
                dummy->left = NULL;
                dummy->right = _root;
                _root->parent = dummy;

                remove_color = del->getColor();
                nil.parent = NULL;

                if (del->left == NULL && del->right == NULL)
                {
                    replace = &nil;
                    if (del->isLeftChild())
                        del->parent->left = &nil;
                    else
                        del->parent->right = &nil;
                    replace->parent = del->parent;
                }
                else if (del->left == NULL || del->right == NULL)
                {
                    if (del->left != NULL)
                        replace = del->left;
                    else
                        replace = del->right;
                        
                    if (del->isLeftChild())
                    {
                        del->parent->left = replace;
                        replace->parent = del->parent;
                    }
                    else
                    {
                        del->parent->right = replace;
                        replace->parent = del->parent;
                    }
                }
                else
                {
                    _Nodeptr    successor = del->right->getMinNode();

                    if (successor->right == NULL)
                        replace = &nil;
                    else
                        replace = successor->right;
                    
                    replace->parent = successor->parent;

                    if (successor->isLeftChild())
                        successor->parent->left = replace;
                    else
                        successor->parent->right = replace;

                    replaceNode(del, successor);

                    remove_color = successor->getColor();
                    successor->setColor(del->getColor());
                }

                if (dummy->right != _root)
                    _root = dummy->right;

                if (remove_color == BLACK)
                    fixRemoveRBTree(replace, dummy);

                _root->parent = NULL;
                _allocator.deallocate(dummy, 1);

                if (&nil == _root)
                    _root = NULL;
                else if (nil.isLeftChild())
		            nil.parent->left = NULL;
	            else if (nil.isRightChild())
		            nil.parent->right = NULL;
                
                return del;
            }
            void rotateLeft(_Nodeptr node)
            {
                _Nodeptr old_right;

                node->right->parent = node->parent;
                if (node->isLeftChild())
                    node->parent->left = node->right;
                else if (node->isRightChild())
                    node->parent->right = node->right;
                node->parent = node->right;
                if (node->right->left)
                    node->right->left->parent = node;
                old_right = node->right;
                node->right = node->right->left;
                old_right->left = node;
            }
            void rotateRight(_Nodeptr node)
            {
                _Nodeptr old_left;

                node->left->parent = node->parent;
                if (node->isLeftChild())
                    node->parent->left = node->left;
                else if (node->isRightChild())
                    node->parent->right = node->left;
                node->parent = node->left;
                if (node->left->right)
                    node->left->right->parent = node;
                old_left = node->left;
                node->left = node->left->right;
                old_left->right = node;
            }
            void fixInsertRBTree(_Nodeptr node)
            {
                _Nodeptr dummy;
                _Nodeptr uncle;

                dummy = _allocator.allocate(1);
                dummy->setColor(BLACK);
                dummy->left = NULL;
                dummy->right = _root;

                _root->parent = dummy;

                while (node->parent->getColor() == RED)
                {
                    uncle = node->getUncle();
                    if (uncle && uncle->getColor() == RED)
                    {
                        node->parent->changeColor();
                        uncle->changeColor();
                        node->parent->parent->changeColor();
                        node = node->parent->parent;
                    }
                    else
                    {
                        if (node->parent->isLeftChild())
                        {
                            if (node->isRightChild())
                            {
                                node = node->parent;
                                rotateLeft(node);
                            }
                            node->parent->changeColor();
                            node->parent->parent->changeColor();
                            rotateRight(node->parent->parent);
                        }
                        else
                        {
                            if (node->isLeftChild())
                            {
                                node = node->parent;
                                rotateRight(node);
                            }
                            node->parent->changeColor();
                            node->parent->parent->changeColor();
                            rotateLeft(node->parent->parent);
                        }
                    }
                }

                if (dummy->right != _root)
                    _root = dummy->right;
                _root->parent = NULL;
                    
                _allocator.deallocate(dummy, 1);

                _root->setColor(BLACK);
            }
            void fixRemoveRBTree(_Nodeptr node, _Nodeptr dummy)
            {
                _Nodeptr sibling;

                while (node != _root && node->getColor() == BLACK)
                {
                    if (node->isLeftChild())
                    {
                        sibling = node->parent->right;
                        if (sibling && sibling->getColor() == RED)
                        {
                            sibling->setColor(BLACK);
                            node->parent->setColor(RED);
                            rotateLeft(node->parent);
                            sibling = node->parent->right;
                        }
                        if ((!sibling->left || sibling->left->getColor() == BLACK) && (!sibling->right || sibling->right->getColor() == BLACK))
                        {
                            sibling->setColor(RED);
                            node = node->parent;
                        }
                        else
                        {
                            if (!sibling->right || sibling->right->getColor() == BLACK)
                            {
                                sibling->left->setColor(BLACK);
                                sibling->setColor(RED);
                                rotateRight(sibling);
                                sibling = node->parent->right;
                            }
                            sibling->setColor(node->parent->getColor());
                            node->parent->setColor(BLACK);
                            sibling->right->setColor(BLACK);
                            rotateLeft(node->parent);

                            if (dummy->right != _root)
                                _root = dummy->right;
                            node = _root;
                        }
                    }
                    else
                    {
                        sibling = node->parent->left;
                        if (sibling && sibling->getColor() == RED)
                        {
                            sibling->setColor(BLACK);
                            node->parent->setColor(RED);
                            rotateRight(node->parent);
                            sibling = node->parent->left;
                        }
                        if ((!sibling->right || sibling->right->getColor() == BLACK) && (!sibling->left || sibling->left->getColor() == BLACK))
                        {
                            sibling->setColor(RED);
                            node = node->parent;
                        }
                        else
                        {
                            if (!sibling->left || sibling->left->getColor() == BLACK)
                            {
                                sibling->right->setColor(BLACK);
                                sibling->setColor(RED);
                                rotateLeft(sibling);
                                sibling = node->parent->left;
                            }
                            sibling->setColor(node->parent->getColor());
                            node->parent->setColor(BLACK);
                            sibling->left->setColor(BLACK);
                            rotateRight(node->parent);

                            if (dummy->right != _root)
                                _root = dummy->right;
                            node = _root;
                        }
                    }
                    if (dummy->right != _root)
                        _root = dummy->right;
                }
                node->setColor(BLACK);
            }
            void fixRoot()
            {
                while (_root->parent != NULL)
                    _root = _root->parent;
            }
            void removeTree(_Nodeptr node)
            {
                if (node == NULL)
                    return ;
                removeTree(node->left);
                removeTree(node->right);
                removeNode(node);
            }
            _Nodeptr findTarget(_Nodeptr cur, const value_type& target) const
            {
                if (cur == NULL)
                    return NULL;

                if (_comp(target, cur->data)) 
                    cur = findTarget(cur->left, target);
                else if (_comp(cur->data, target)) 
                    cur = findTarget(cur->right, target);

                return cur;
            }
            void replaceNode(_Nodeptr dest, _Nodeptr src)
            {
                if (dest->left)
                    dest->left->parent = src;
                src->left = dest->left;
                if (dest->right)
                    dest->right->parent = src;
                src->right = dest->right;
                if (dest->isLeftChild())
                    dest->parent->left = src;
                else if (dest->isRightChild())
                    dest->parent->right = src;
                src->parent = dest->parent;
            }
        public:
            rb_tree() : _allocator(allocator_type()), _comp(key_compare()), _root(NULL), _size(0) {};
            rb_tree(allocator_type alloc, key_compare comp) : _allocator(alloc), _comp(comp), _root(NULL), _size(0) {};
            ~rb_tree()
            {
                removeTree(_root);
            }
            _Nodeptr get(const value_type& target) const
            {
                return findTarget(_root, target);
            }
            bool contains(const value_type& target) const
            {
                return findTarget(_root, target) != NULL ? true : false;
            }
            bool insert(value_type new_data)
            {
                _Nodeptr new_node = createNode(new_data);
                if (!insertBST(new_node))
                {
                    removeNode(new_node);
                    return false;
                }
                _size++;
                return true;
            }
            bool remove(const value_type& target)
            {
                _Nodeptr del = removeBST(target);
                if (del == NULL)
                    return false;
                removeNode(del);
                _size--;
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
            _Nodeptr getMinNode() const
            {
                return _root->getMinNode();
            }
            _Nodeptr getMaxNode() const
            {
                return _root->getMaxNode();
            }
            void swap(rb_tree<T, Compare, Allocator> &x)
            {
                ft::swap(_root, x._root);
                ft::swap(_size, x._size);
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
                    typedef ft::_node<value_type>       _Node;
                    typedef ft::_node<value_type>*      _Nodeptr;
                private:
                    _Nodeptr _cur;
                    bool    _is_end;
                public:
                    iterator() : _cur(NULL), _is_end(true) {}
                    iterator(_Nodeptr node, bool is_end) : _cur(node), _is_end(is_end) {}
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
                            _Nodeptr ptr = _cur;
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
                            _Nodeptr ptr = _cur;
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
                    typedef ft::_node<value_type>       _Node;
                    typedef ft::_node<value_type>*      _Nodeptr;
                private:
                    const _Nodeptr  _cur;
                    bool            _is_end;
                public:
                    const_iterator() : _cur(NULL), _is_end(false) {}
                    const_iterator(_Nodeptr *node, bool is_end) : _cur(node), _is_end(is_end) {}
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
                            const _Nodeptr ptr = _cur;
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
                            const _Nodeptr ptr = _cur;
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