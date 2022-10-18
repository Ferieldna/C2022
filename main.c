#include <stdio.h>
#include <stdlib.h>

struct noeud {
  char *val;
  struct noeud *g;
  struct noeud *d;
};

typedef struct noeud *ab;

/*creation dun neoud*/

ab creat(char *v, ab ls, ab rs)
{
  ab res;
  res  = (ab) malloc(sizeof(struct noeud));
  if (res == NULL) {
    fprintf(stderr, "Impossible d'allouer le noeud");
    return NULL;
  }

  res-> val = v;
  res->g = ls;
  res->d = rs;

  return res;
}
void ajout(ab* pr, char *elt)
{
  if (pr==NULL) {
    printf("Erreur.");
    exit(1);
  }
  else if ((*pr) == NULL)
    *pr = creat(elt,NULL,NULL);
  else if ((*pr)->g == NULL)
    (*pr)->g = creat(elt,NULL,NULL);
  else if ((*pr)->d == NULL)
    (*pr)->d = creat(elt,NULL,NULL);
  else ajout( &((*pr)->g), elt);
}

void afficheracine(ab n)
{ if (n != NULL) {
    printf("%s\n", n->val);}
}
void parcourirArbre(ab n)
{
  if (n != NULL) {
    //printf("%d ", n->val);
    if((n->g) != NULL)
      printf("%s\n", n->g->val);
    if((n->d) != NULL)
      printf("%s\n", n->d->val);
    parcourirArbre(n->g);
  }
}
int main(void)
{
  ab ls = NULL;
  ab rs = NULL;

  rs = creat("a", ls, rs);
  afficheracine(rs);
  ajout(&rs, "Bonjour");
  ajout(&rs, "tout");
  ajout(&rs, "le");
  ajout(&rs, "monde");
  parcourirArbre(rs);
  return 0;
}