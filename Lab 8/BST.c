#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"BST.h"
#include"stack.h"
Bst create(Element e){
	Bst b = (Bst)malloc(sizeof(struct bst));
	assert(b!=NULL);
	b -> e = e;
	b -> left = NULL;
	b -> right = NULL;
	b -> height = 0;
	return b;
}


int getHeight(Bst a){
    if(a==NULL)
        return -1;
    else
        return a->height;
}
void updateHeight(Bst b){
    if(b!=NULL){
        int c = 0;
        if(b -> left !=NULL){
            c = getHeight(b->left)+1; 
        }
        if(b->right!=NULL){
            c = getHeight(b->right)+1>c?getHeight(b->right)+1:c;
        }
        b -> height = c;
    }
}
//Assume that there are only two cases
Bst rotate(Bst Z, Bst pZ){
    Bst a,c,b,Y,X;
    if(getHeight(Z->left) >getHeight( Z->right)+1){
        if(getHeight(Z->left->left) > getHeight(Z->left->right)){
            c=Z;
            Y = Z->left;
            X = Z->left->left;
            b = Z->left;
            a = Z->left->left;
        }
        else{
            Y = Z->left;
            X = Z->left->right;
            c = Z;
            b = Z->left->right;
            a = Z->left;
        }
    }
    else{
        if(getHeight(Z->right->left)>getHeight(Z->right->right)){
            a = Z;
            b = Z->right->left;
            c = Z->right;
            Y = Z->right;
            X = Z->right->left;
        }
        else{
            a = Z;
            b = Z->right;
            c = Z->right->right;
            Y = Z->right;
            X = Z->right->right;
        }
    }

    if(Y==b){
        if(X==c){
            Z->right = Y->left;
            Y->left = Z;
            updateHeight(Z);
            updateHeight(X);
            updateHeight(Y);
        }

        else if(X==a){
            Z->left = Y->right;
            Y->right = Z;
            updateHeight(Z);
            updateHeight(X);
            updateHeight(Y);
            //return;
        }if(pZ!=NULL){
            if(pZ->left == Z)
                pZ->left = Y;
            else
                pZ->right = Y;
            updateHeight(pZ);
            return pZ;
    }
        return Y;
    }
    if(X==b){
        if(Y==c){
            Y->left = X->right;
            X->right = Y;
            Z->right = X->left;
            X->left = Z;
            updateHeight(Z);
            updateHeight(Y);
            updateHeight(X);
        }
        else if(Y==a){
            Y->right = X->left;
            X->left = Y;
            Z->left = X->right;
            X->right = Z;
            updateHeight(Z);
            updateHeight(Y);
            updateHeight(X);
        }
        if(pZ!=NULL){
        if(pZ->left == Z)
            pZ->left = X;
        else
            pZ->right = X;
        updateHeight(pZ);
        return pZ;
        }
        return X;
    }
}
int isImbalanced(Bst b){
    if(b==NULL)
        return 0;
    int c,d;
    if(b->left==NULL)
        c = 0;
    else
        c = b->left->height+1;
    if(b->right ==NULL)
        d = 0;
    else
        d = b->right ->height+1;
    if(((c-d)>1)||((d-c)>1)){
     //debug here
        printf("debug");
        return 1;
    }
    else
        return 0;
}

Bst batchUpdateHeight(Stack s){
    Bst t1=NULL;Bst t2=NULL;Bst t3;
    while(s->head!=NULL){
        Bst b = getTop(s);
        updateHeight(b);
        s = deleteFromStack(s);
        if(isImbalanced(b)){
            t3 = rotate(b,getTop(s));
        }
        else
            t3 = b;
        t1 = t2;
        t2 = b;
    }
    return t3;

}




void print(Bst b){
    if(b!=NULL)
        printf("%d,",b->e->value);
    else
        printf("%d,",-1);
}

void visualizeBst(Bst b){
    Stack s1 = createStack();
    Stack s2 = createStack(); 
    s1 = addToStack(s1,b);
    while(1){
        while(s1->head!=NULL){
            Bst b = getTop(s1);
            print(b);
            if(b!=NULL){
                s2 = addToStack(s2,b->left);
        //    if(b->right!=NULL)
                s2 = addToStack(s2,b->right);
            }
            s1 = deleteFromStack(s1);
        }
        printf("\n");
        if(s2->head == NULL)
            break;
        while(s2->head!=NULL){
            Bst b = getTop(s2);
            s1 = addToStack(s1,b);
            s2 = deleteFromStack(s2);
        }
    }
}


Bst addB(Bst b, Element e){

	if(b==NULL)
        return create(e);
    Bst c = b;
    Stack s = createStack();
	while(c!=NULL){
        s = addToStack(s,c);
		if(c->e->value < e->value){
			//c -> height++;
			if(c->right==NULL){
				//c->height++;
				c->right = create(e);
                s = addToStack(s,c->right);
               b =  batchUpdateHeight(s);
				return b;
			}
			else{
				//c -> height++;
				c = c->right;
			}
		}
		else{// if(c ->e -> value >= e -> value) {
			c->height--;
			if(c->left == NULL){
				c->left = create(e);
                s = addToStack(s,c->left);
               b =  batchUpdateHeight(s);
				return b;
			}
			else{
				c = c->left;
			}
		}
	//	else
	//		return b;
	}
}

/*Bst find(Bst b, Element e){
//	if
}*/

Bst extractPredecessor(Bst b){
	Stack s = createStack();
    Bst p = b;
	if(b == NULL)
		return NULL;
	b = b->left;
    if(b==NULL)
        return NULL;
    // s = addToStack(s,b);
    int flag =0;
	while(b->right!=NULL){
        flag = 1;
		p = b;
		b = b->right;
        s = addToStack(s,p);
	}
            if(flag==0){
			    p->left = b->left;
            }

	    	else if(flag==1){
		    	p->right = b->left;
		    }
        
        s = addToStack(s,b->left);
       batchUpdateHeight(s);
		return b;
	
}

Bst deleteB(Bst b, Element e){
	Bst c = b;
	Bst p = b;
	int flag = 0;
    Stack s = createStack(s);
	//check record also and not just key

	if(p->e->value > e->value){
		c = p->left;
	}
	else if(p->e->value < e->value){
		c = p->right;
	}
	else{// c==value
	    Bst i = extractPredecessor(p);
	    i -> left = c -> left;
	    i -> right = c-> right;
        updateHeight(i);
	    return i;
	}
    s = addToStack(s,p);
	while(c!=NULL){
		if(c->e->value == e->value){
	//		Bst e = extractPredecessor(e);
		//cases
		//one of the sub trees is null
		//both the  sub trees are null
			if(c->left == NULL){
				if(c->right!=NULL){
				//check which child of parent
					if(p->left == c){
						//p->left = extractPredecessor(C);
						p->left = c->right;
					}
				//else p->right ==c
					else{
						//p->right = extractPredecessor(c);
						p->right = c->right;
					}
                 s = addToStack(s,c->right);
                b =    batchUpdateHeight(s);
					//found and deleted
					return b;
				}
				else{
					if(p->left == c){
						p->left = NULL;
					}
					else{ //p->right == c
						p->right = NULL;
					}
                   b = batchUpdateHeight(s);
					//found at leaf and deleted
					return b;
				}
			}
			else if( c->right == NULL){
				if(p->left == c){
					p->left = c->left;
				}
				else{ //p->right == c	
					p->right = c->left;
				}
             s = addToStack(s,c->left);
             b =   batchUpdateHeight(s);
				//found and deleted
				return b;
			}
			else{ //neither == NULL
				Bst i = extractPredecessor(c);
               // s = addToStack(s,i);
				//attach i to parent of c
				if(p->left == c)
					p->left = i;
				else
					p->right = i;
				i -> left = c->left;
				i -> right = c -> right;
				//found and deleted
                s = addToStack(s,i);
                b = batchUpdateHeight(s);
				return b;
			}
		}
		// unite all return calls and free c if deleted
		//prepare for next level, update parent
		p = c;
        s = addToStack(s,p);
		if(c->e->value < e->value){
			//p = c;
			c = c->right;
		}
		else // c is > element
			c = c->left;
	}
	//not found hence not deleted
	return b ;
}






int main1(){
    Element e = (Element)malloc(sizeof(struct element));
    e -> value = 10;
    Bst b = create(e);
    b = addB(b,e);
    b = addB(b,e);
     deleteB(b,e);
    visualizeBst(b);
    return 0;
}
