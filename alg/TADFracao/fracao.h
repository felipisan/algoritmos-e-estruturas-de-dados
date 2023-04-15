typedef enum erros {
	sem_erro, div_zero, memoria, ponteiro_invalido
} erro_t;

typedef struct frac fracao_t;

// 
fracao_t *criar_fracao(int num, int den, erro_t *erro);
void imprimir_fracao(fracao_t *f);
void destruir_fracao(fracao_t *f);
fracao_t *somar_fracao(fracao_t *f1, fracao_t *f2, erro_t *erro);
void simplificar_fracao(fracao_t *f);