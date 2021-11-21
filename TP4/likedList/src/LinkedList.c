#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len;
	len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		pNode=this->pFirstNode;
		for(int i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
		}
	}
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node* pNode = NULL;
	Node* pNodeViejo = NULL;

	int len = ll_len(this);

	if (this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		pNode = (Node*) malloc(sizeof(Node));
		pNodeViejo = (Node*) malloc(sizeof(Node));

		if(pNode != NULL)
		{
			if(nodeIndex == 0) //si quiero ingresarlo al indice 0
			{
				pNodeViejo = getNode(this,nodeIndex);
				pNode->pNextNode = pNodeViejo;
				this->pFirstNode = pNode;
				pNode->pElement = pElement;
				this->size++;
				returnAux=0;
			}
			else //si ya hay nodos en la lista
			{
				pNodeViejo = getNode(this,nodeIndex);
				pNodeViejo->pNextNode = pNode->pNextNode;
				pNodeViejo->pNextNode = pNode;
				pNode->pElement = pElement;
				this->size++;
				returnAux=0;
			}
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if (this!=NULL)
	{
		if(addNode(this,len, pElement) != -1)
		{
			returnAux = 0;
		}
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    int len;

    len = ll_len(this);
    pNode = (Node*) malloc(sizeof(Node));

    if(this !=NULL && index >= 0 && index <= len)
    {
        pNode=getNode(this, index);

        if(pNode != NULL)
        {
            returnAux = pNode->pElement;
        }
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = (Node*) malloc (sizeof(Node));
    	pNode=getNode(this, index);

    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pNodeAux = NULL;
    int len;
    int indexAux;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	if(index == 0)
    	{
    		pNode = getNode(this, index);
    		this->pFirstNode = pNode->pNextNode;
    		free(pNode);
    	}
    	else
    	{
    		indexAux = index - 1;
    		pNode = getNode(this, index);
    		pNodeAux = getNode(this, indexAux);
    		pNodeAux->pNextNode = pNode->pNextNode;
    		free(pNode);
    	}
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    len =ll_len(this);

    if(this!=NULL)
    {
        for(int i=len; i==0; i--)
        {
            ll_remove(this, i);
        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL)
    {
    	pNode = (Node*) malloc(sizeof(Node));
    	for(int i=0;i<=len;i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL)
    		{
    			if(pNode->pElement == pElement)
    			{
    				returnAux = i;
    				break;
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        if (this->size>0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	if(addNode(this, index, pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = (Node*) malloc(sizeof(Node));
    	pNode = getNode(this, index);

    	if(pNode != NULL && ll_remove(this, index) == 0)
    	{
    		returnAux = pNode;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int len;
    int contiene = 1;

    len = ll_len(this);

    if(this != NULL && pElement != NULL)
    {
    	for(int i=0;i<=len;i++)
    	{
    		pNode = getNode(this, i);
    		if(pNode != NULL)
    		{
    			if(pNode->pElement==pElement)
    			{
    				returnAux = 1;
    				contiene = 0;
    				break;
    			}
    		}
    	}
    	if(contiene)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int flag = 0;
    int len;
    Node* pNodeList2 = NULL;

    pNodeList2 = (Node*) malloc(sizeof(Node));
    len = ll_len(this2);

    if(this != NULL && this2 != NULL)
    {
    	for (int i=0; i<len; i++)
		{
    		pNodeList2 = ll_get(this2,i);
			if ((ll_contains(this, pNodeList2))==1)
			{
				flag++;
			}
		}
		if (flag == len)
		{
			returnAux = 1;
		}
		else
		{
			returnAux=0;
		}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementosIndicados = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && from >= 0 && from <= len && to >= 0 && to <= len)
    {
    	cloneArray = ll_newLinkedList();
    	for(int i = from; i <= to ; i++)
    	{
    		pElementosIndicados = ll_get(this, i);
    		ll_add(cloneArray, pElementosIndicados);
    	}
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) //preguntar si puedo hacer una sublist desde 0 al len
{
    LinkedList* cloneArray = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, len);
    }
    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementoAuxiliar = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	for(int i=0;i<len;i++)
    	{
    		for(int j=1;j<=len;j++)
    		{
    			if(order == 0 && pFunc(ll_get(this, i), ll_get(this, j))<0)
				{
    				pElementoAuxiliar = ll_get(this,i);
					ll_set(this, i, ll_get(this,j));
					ll_set(this, j, pElementoAuxiliar);
				}
				else if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j))>0)
				{
					pElementoAuxiliar = ll_get(this,i);
					ll_set(this, i, ll_get(this,j));
					ll_set(this, j, pElementoAuxiliar);
				}
    		}
    	}
    }
    return returnAux;
}
