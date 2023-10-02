
/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param volume Um ponteiro para uma variável float para armazenar o volume calculado.
 */
void CalculaVolume (float R, float *volume)
{
    float volumeCalc = R*R*R*PI*3/4 ;
    *volume = volumeCalc;
}

/**
 * @brief Calcula a área de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param area Um ponteiro para uma variável float para armazenar a área calculada.
 */
void CalculaArea (float R, float *area)
{
    float areaCalc = PI*R*R;
    *area = &areaCalc;
}