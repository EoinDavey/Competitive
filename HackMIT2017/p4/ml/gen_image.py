from keras.utils import np_utils
from keras.models import load_model
from keras import backend as K
from scipy.misc import imsave
import numpy as np

JSON_PATH = "../EoinDavey.json"
HDF5_PATH = "../EoinDavey_model.hdf5"
img_w = 32
img_h = 32
step = 1

model = load_model(HDF5_PATH)

output = model.layers[14].output

loss = K.mean(output[:, 1])

input_img = model.input

grads = K.gradients(loss, input_img)[0]

grads /= (K.sqrt(K.mean(K.square(grads))) + 1e-5)

iterate = K.function([input_img], [loss, grads])

def dep_image(x):
    x-=x.mean()
    x/=(x.std()+1e-5)
    x*=0.1
    x+=0.5
    x = np.clip(x,0,1)
    x*=255
    #x = x.transpose((1,2,0))
    x=np.clip(x,0,255).astype('uint8')
    return x


for k in range(10):
    input_img_data = np.random.random((1,img_w,img_h,3)) * 20 + 128
    for i in range(10000):
        loss_value, grads_value = iterate([input_img_data])
        input_img_data += grads_value * step
    img = input_img_data[0]
    img = dep_image(img)
    imsave('pic%d.png' % k, img)
