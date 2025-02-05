#include <stdio.h>
#include <math.h> 

int comb(int n, int x, int ene, int xis){
    //começo da conta de Combinação
    //C n,x = ( n! )/ ( (n - x) * (x!) )
    
    int nx, enexis, fatN, fatX, fatNX, com;

    nx = ene - xis;
    enexis = nx;
    
    //fatorial de x
    for(fatX = 1; x > 1; x--)
        fatX = fatX * x;
    //fatorial de n  
    for(fatN = 1; n > 1; n--)  
        fatN = fatN * n;            
    //fatorial de n - x
    for(fatNX = 1; nx > 1; nx--)
        fatNX = fatNX * nx;
    //conta 
    com = fatN / (fatNX * fatX);
    
    
    printf("\nC %d, %d =  ( %d! )\n", ene, xis, ene);
    printf("         ---------\n");
    printf("         ( %d )! %d!\n", enexis, xis);
    printf(" = %d\n", com);

    return com;
}

double pex(double p, int xis){
    double expo;

    expo = pow(p, xis);
    
    return expo;
}

double qnx(double p, int xis, int ene){
    int expNX;
    double q, res;

    q = 1 - p;
    expNX = ene - xis;

    res = pow(q, expNX);
    
    return res;
}  

int main(){
    int ene, xis, n, x, combinacao;
    double p, PEX, QNX, q, resposta, final;

    //pedindo os valores de n, p e x
    printf("Digite o numero de observacoes: \n");
    scanf("%d", &ene);
    printf("Digite o numero especificado de sucesso: \n");
    scanf("%d", &xis);
    printf("Digite a probabilidade de sucesso: \n");
    scanf("%lf", &p);

    n = ene;
    x = xis;
    q = 1 - p;

    //chamando função combinação
    combinacao = comb(n, x, ene, xis);
    //chamando função de calcular o P elevado a X
    PEX = pex(p, xis);
    //chamando função de calcular o q elavado a n - x
    QNX = qnx(p, xis, ene);

    //resultado final
    resposta = (combinacao) * (PEX) * (QNX);
    final = resposta*100;
    
    printf("\nP(%d) = %d * ( %.2lf ^ %d ) * ( %.2lf ^ %d - %d ) = %.4lf\n", x, combinacao, p, xis, q, ene, xis, resposta);
    printf("Resposta em porcentagem: %.2lf%%\n", final);

    return 0;
}