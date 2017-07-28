import numpy as np
import matplotlib.pyplot as plt

mapa = np.genfromtxt('map_data.txt')
datos = np.genfromtxt('datos.txt')

r = datos[0]
y = datos[1]
x = datos[2]

fig, ax = plt.subplots()
circunferencia = plt.Circle((x, y), r, alpha = 0.2, color = 'black')
ax.add_artist(circunferencia)
ax.add_artist(plt.imshow(mapa, cmap = 'winter'))
ax.set_title('Punto Nemo')
plt.savefig('PuntoNemo.pdf')
plt.close()
