#include "../../include/bst.h"
#include "../../include/question.h"
#include "../../include/utils.h"

void run_questao1() {

  BST *bst = createBST();

  for (li i = 0; i < 20; i++) {
    insertBST(bst, genRandomNumber(1, 100));
  }

  printf("\n# Pré-fixado\n");
  preOrderBST(bst);

  printf("\n# In-fixado\n");
  inOrderBST(bst);

  printf("\n# Pós-fixado\n");
  postOrderBST(bst);

  destroyBST(bst);
}