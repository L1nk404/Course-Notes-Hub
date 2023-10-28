# Constantes = "Variáveis" que não vão mudar
# Muitas condições no mesmo if (ruim)
#     <- Contagem de complexidade (ruim)

velocidade = 61  # velocidade atual do carro
local_do_carro = 101  # local em que o carro se encontra

RADAR_1 = 60  # velocidade máxima de radar 1
LOCAL_1 = 100  # local onde o radar 1 está
RADAR_RANGE = 1  # A distância onde o radar pega
RADAR_INF = LOCAL_1 - RADAR_RANGE  
RADAR_SUP = LOCAL_1 + RADAR_RANGE
INTERVALO_RADAR = (RADAR_INF) <= local_do_carro <= (RADAR_SUP) 

if velocidade > RADAR_1 and INTERVALO_RADAR:
    print('Multado.')
else:
    print('Não multado.')

