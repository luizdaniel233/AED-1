#include <stdio.h>
#include <math.h>
#define PI 3.14

float volumeEsfera(float);
float volumeCilindro(float, float);
float volumeCalota(float, float);

float calculaVolume(float raio, float hCal)
{
    float raioCil, hCil, volume;

    hCil = (2 * raio) - (2* hCal);
	//printf("%f\n", hCil);

    raioCil = sqrt(pow(raio, 2) - pow(hCil/2, 2));

    volume = volumeEsfera(raio) - volumeCilindro(raioCil, hCil) - 2 * volumeCalota(raio, hCal);

    return (volume);
}
float volumeEsfera(float rEsfera)
{
    float vEsfera;

    vEsfera = (4 * PI * pow(rEsfera, 3)) / 3;

    return (vEsfera);
}
float volumeCilindro(float rCilindro, float hCilindro)
{
    float vCilindro;

    vCilindro = (PI * pow(rCilindro, 2) * hCilindro);

    return (vCilindro);
}
float volumeCalota(float rCalota, float hCalota)
{
    float vCalota;

    vCalota = (PI * pow(hCalota, 2) * (3 * rCalota - hCalota)) / 3;

    return (vCalota);
}
int main(void)
{
    float raio, hCal, resultado;

    scanf("%f%f", &raio, &hCal);

    resultado = calculaVolume(raio, hCal);

    printf("%.2f\n", resultado);

    return 0;
}
