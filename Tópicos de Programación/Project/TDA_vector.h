#ifndef TDA_VECTOR_H_INCLUDED
#define TDA_VECTOR_H_INCLUDED

#define TAM_MAX 10

typedef struct
{
    void *vec;
    int ce;
    unsigned tam_max;
    unsigned tamanio;
}TDA_vector;

int TDA_Crear_vector(TDA_vector *v, unsigned tamanio);
int TDA_InsertarOrdenado(TDA_vector *v, void *valor, int Comparar(const void*,const void*));
int TDA_Insertar_al_final(TDA_vector *v, void *valor);
int TDA_bsearch(TDA_vector *v, void *clave, int cmp(const void*,const void*));
int TDA_bSeq(TDA_vector *v, void *clave, int cmp(const void*,const void*));
void* TDA_BuscarExtremo(TDA_vector *buffer, int ce_real ,int comparar(const void*,const void*));
void TDA_sort(TDA_vector *buffer, int comparar(const void*, const void*));
int TDA_Vector_lleno(TDA_vector *v);
int TDA_Vector_vacio(TDA_vector *v);
int TDA_ce(TDA_vector *v);
void* TDA_map(TDA_vector *v, void Accion(void*));
int TDA_Destruir_vector(TDA_vector *v);
int TDA_Duplicar_tamanio(TDA_vector *v);

#endif // TDA_VECTOR_H_INCLUDED
