# Definição dos Tipos Abstratos de Dados (TAD)

## Vector (Array Dinâmico)

### Atributos do Vector

- dados: ponteiro para inteiro (alocado dinamicamente)
- tamanho: inteiro

### Construtores / Destrutores do Vector

- createVetor:  vector\* (int tamanho)
- destroyVetor: void (Vector \*self)

### Operações Públicas do Vector

- linearSearchVetor: int (vector \*self, int target)
- binarySearchVetor: int (vector \*self, int target)
- bubbleSort:    void (Vector \*self)
- insertionSort: void (Vector \*self)
- selectionSort: void (Vector \*self)
- quickSort:     void (Vector \*self)
- mergeSort:     void (Vector \*self)
- getSize:      int (Vector \*self)
- getElementAt: int (Vector \*self, int index)
- setElementAt: void (Vector \*self, int index, int value)

---

## BST (Árvore Binária de Pesquisa)

### Atributos do BST

- raiz: ponteiro para NodeBST
- tamanho: inteiro

### Atributos do NodeBST (interno)

- chave: inteiro
- esq: ponteiro para NodeBST
- dir: ponteiro para NodeBST

### Construtores / Destrutores do BST

- createBST:  BST\* ()
- destroyBST: void (BST \*self)

### Operações Públicas do BST

- insertBST:    void (BST \*self, int chave)
- deleteBST:    void (BST \*self, int chave)
- searchBST:    int  (BST \*self, int chave)
- heightBST:    int  (BST \*self)
- sizeBST:      int  (BST \*self)
- isEmptyBST:   int  (BST \*self)
- preOrderBST:  void (BST \*self)
- inOrderBST:   void (BST \*self)
- postOrderBST: void (BST \*self)

### Operações Internas do BST

- createNodeBST:   NodeBST\* (int chave)
- destroyNode:     void     (NodeBST \*node)
- insertNode:      NodeBST\* (NodeBST \*node, int chave, int \*inserido)
- deleteNodeBST:   NodeBST\* (NodeBST \*node, int chave, int \*removido)
- searchNode:      int      (NodeBST \*node, int chave)
- heightNode:      int      (NodeBST \*node)
- findMin:         NodeBST\* (NodeBST \*node)
- preOrder:        void     (NodeBST \*node)
- inOrder:         void     (NodeBST \*node)
- postOrder:       void     (NodeBST \*node)

---

## NodeAVL

### Atributos do NodeAVL

- chave: inteiro
- altura: inteiro
- esq: ponteiro para NodeAVL
- dir: ponteiro para NodeAVL

### Operações Públicas do NodeAVL

- createNodeAVL:  NodeAVL\* (int chave)
- destroyNodeAVL: void (NodeAVL \*self)

---

## AVL (Árvore AVL)

### Atributos do AVL

- raiz: ponteiro para NodeAVL
- tamanho: inteiro

### Construtores / Destrutores do AVL

- createAVL:  AVL\* ()
- destroyAVL: void (AVL \*self)

### Operações Públicas do AVL

- insertAVL:    void (AVL \*self, int chave)
- deleteAVL:    void (AVL \*self, int chave)
- searchAVL:    int  (AVL \*self, int chave)
- heightAVL:    int  (AVL \*self)
- sizeAVL:      int  (AVL \*self)
- isEmptyAVL:   int  (AVL \*self)
- preOrderAVL:  void (AVL \*self)
- inOrderAVL:   void (AVL \*self)
- postOrderAVL: void (AVL \*self)

### Operações Internas do AVL

- insertNode:         NodeAVL\* (NodeAVL \*node, int chave)
- deleteNode:         NodeAVL\* (NodeAVL \*node, int chave)
- searchNode:         int      (NodeAVL \*node, int chave)
- heightNode:         int      (NodeAVL \*node)
- fatorBalanceamento: int      (NodeAVL \*node)
- balancear:          NodeAVL\* (NodeAVL \*node)
- minNode:            NodeAVL\* (NodeAVL \*node)
- destroyNode:        void     (NodeAVL \*node)
- preOrder:           void     (NodeAVL \*node)
- inOrder:            void     (NodeAVL \*node)
- postOrder:          void     (NodeAVL \*node)
- rotateLeft:         NodeAVL\* (NodeAVL \*node)
- rotateRight:        NodeAVL\* (NodeAVL \*node)
- rotateLeftRight:    NodeAVL\* (NodeAVL \*node)
- rotateRightLeft:    NodeAVL\* (NodeAVL \*node)
