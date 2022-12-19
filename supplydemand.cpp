#include <iostream>
int main(){
    FILE *fp = fopen("supplyDemandData.xls", "w+");
    float a = 1.0, b = 0.9, c = 12.4, d = 1.2;
    float s,q,p = 1.0;
    int i, n;
    printf("Enter the number of data to be modeled: ");
    scanf("%d", &n);

    fprintf(fp,"%s \t %s \t %s \n","Supply", "Quantity", "Price");
    for(i<0; i<=n; i++){
        s = a + b*p;
        q = s;
        p = (c-q)/d;
        fprintf(fp,"%f \t %f \t %f \n", s, q, p);
    }
    fclose(fp);
    return 0;
}
