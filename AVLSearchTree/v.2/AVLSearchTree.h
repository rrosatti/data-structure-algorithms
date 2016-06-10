#include <cstddef>
#include <iostream>

typedef int ItemType;

struct Node
{
  ItemType label;
  int      fatorB;
  Node*    esquerda;
  Node*    direita;
};

class AVLSearchTree
{
 public:  
  AVLSearchTree() {
    root = NULL;
  }
    
  ~AVLSearchTree(){
    destroyTree(root);
  }

  // Ignore este metodo, jah esta completamente implementado.
  void printTree() const
  {
    printTree(root);
  }
  
  // Verifica se a arvore possui pelo menos um no.
  bool isEmpty() const;

  // Verificar se eh possivel alocar um novo no.
  bool isFull() const;

/* Todos os metodos publicos abaixo jah estao implementados, nao
   redefina. Voce deverah se preocupar apenas com os metodos privados
   que implementam a funcionalidade invocada por esses metodos
   publicos. */
  
  void retrieveItem(ItemType& item, bool& found) const{
    retrieveItem(root, item, found);
  }

  // Nos metodos seguintes, use os metodos privados de mesmo nome para
  // fazer de forma recursiva.
  void insertItem(ItemType item){
    bool isTaller;
    insertItem(root, item, isTaller);
  }
  
  void deleteItem(ItemType item){
    bool isShorter;
    deleteItem(root, item, isShorter);
  }


 private:

  // Funcoes recursivas que serao usados por algumas das funcoes
  // publicas.


  // O construtor dessa classe invocara destroyTree. Em resumo, voce
  // devera caminhar pela arvore apagando todos os nos que
  // existem. Cuidado com a ordem em que voce faz a chamada ao
  // delete. Garanta que soh invocarah o comando delete apos ambos os
  // filhos terem sido removidos.
  void destroyTree(Node*& tree);


  // O metodo publico chamado de retrieveItem ira fazer uma chamada
  // para este metodo. Implemente este metodo de forma recursiva. Para
  // isso que serve o primeiro parametro Node *tree.
  
  // Voce vai receber um objeto item que serah usado como chave. Apos
  // isso, voce tera que procurar se na sua arvore existe algum noh
  // com essa chave. Se existir, entao voce coloca em "item" (no
  // proprio parametro) o objeto que estava no noh da sua arvore.

  // Use a variavel found para avisar a quem chamou se o objeto item
  // foi alterado ou nao. Em outras palavras, avise em found se o no
  // existe ou nao.
 
  void retrieveItem(Node* tree, ItemType& item, bool& found) const;

  // De forma analoga, os metodos abaixo deverao ser chamados pelos
  // metodos publicos. Os parametros Node*& tree estao ai para voce
  // implementar de forma recursiva.
  void insertItem(Node*& tree, ItemType item, bool& isTaller);

  // Use este metodo privado apenas para navegar pela arvore ate
  // encontrar o no que voce deseja excluir. Feito isso, chame o
  // metodo deleteNode passando como parametro o no que voce
  // encontrou.
  void deleteItem(Node*& tree, ItemType item, bool& isShorter);

  // Nesse metodo, voce receberah como parametro o no que precisa ser
  // removido. Observe que temos tres casos: (i) o no pode ser uma
  // folha, (ii) o no pode ter um filho e (iii) o no pode ter dois
  // filhos. Caso o no tenha dois filhos, voce deverah chamar o metodo
  // getSuccessor para obter o no que deverah substituir o no atual
  // antes da remocao.
  void deleteNode(Node*& tree, bool& isShorter);

  // Procure o sucessor do no atual na arvore. Em outras palavras,
  // procure o no mais a esquerda da arvore da direita.
  void getSuccessor(Node* tree, ItemType& data);


  void printTree(Node *tree) const
  {
    std::cout << "Pre:  ";
    printPreOrder(tree);
    std::cout << std::endl;
    std::cout << "In:   ";
    printInOrder(tree);
    std::cout << std::endl;
    std::cout << "Post: ";
    printPostOrder(tree);
    std::cout << std::endl;
  }
  
  void printPreOrder(Node* tree)  const;
  void printInOrder(Node* tree)   const;
  void printPostOrder(Node* tree) const;


  // Abaixo, tree eh sempre o node que estah desbalanceado
  void rotateToLeft(Node*& tree) const;
  void rotateToRight(Node*& tree) const;  
  void rotateToLeftAndRight(Node*& tree) const;
  void rotateToRightAndLeft(Node*& tree) const;

  // Abaixo, tree eh sempre o unico node que pode estar
  // desbalanceado. A funcao deve decidir se estah ou nao
  // desbalanceado e o que fazer.
  void performRotations(Node*& tree) const;
  
  // Nossa estrutura de dados. Raiz da arvore binaria de busca.
  Node* root;
};
