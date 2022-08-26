import pandas as pd
import numpy as np
import math
import time, datetime
from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.layers.advanced_activations import LeakyReLU
from keras.initializers import Constant

def score(in1,in2):
    assert(len(in1)==len(in2))
    sm = 0.0
    for i in xrange(len(in1)):
        sm+=abs(in1[i]-in2[i])
    sm /= len(in1)
    return sm

def toDate(ux):
    return datetime.datetime.fromtimestamp(int(ux)).strftime('%d/%m/%Y')

np.random.seed(14)

date2res = pd.read_csv("../Data/Bikes.csv",index_col=0)
predictors = pd.read_csv("../Data/Weather.csv",index_col=0)
hdays = pd.read_csv("../Data/Holidays.csv")

df1 = pd.concat([date2res,predictors],axis=1,join="inner")

df1 = df1.dropna(how="any")

df1 = df1.drop(['19/12/2015','09/05/2015','04/04/2016'])

df1 = df1[df1.apply(lambda x: np.abs(x - x.mean()) / x.std() < 3).all(axis=1)]

# Add holidays

hdays = hdays.ix[:,'Date'].apply(toDate)

hdays = pd.concat([hdays.to_frame(),pd.Series([1]*len(hdays))],axis=1)
hdays.columns = ['Date','Holiday']
hdays = hdays.set_index(['Date'])

df1 = pd.concat([df1,hdays],axis=1).fillna(value=0)

# Weekday

wdts = df1.index.values

f = np.vectorize(lambda x: 0 if datetime.datetime.strptime(x,'%d/%m/%Y').weekday() < 5 else 1)
wdts = f(wdts)
wdts = pd.DataFrame({'Date':df1.index.values, 'Weekday':wdts})
wdts = wdts.set_index(['Date'])

df1 = pd.concat([df1,wdts],axis=1,join='inner')

# Split data
y_data = df1[['result']]
x_data = df1[['Weekday','AWND','PRCP','SNOW','TAVG','TMAX','TMIN','Holiday']]

model = Sequential()

model.add(LeakyReLU(alpha=0.2,input_shape=(len(list(x_data)),)))
model.add(Dense(64,kernel_initializer="normal",activation="relu"))
model.add(Dropout(0.25))
model.add(Dense(100,kernel_initializer="normal",activation="relu"))
model.add(Dropout(0.25))
model.add(Dense(100,kernel_initializer="normal",activation="relu"))
model.add(Dropout(0.2))
model.add(Dense(64,kernel_initializer="normal",activation="relu"))
model.add(Dropout(0.2))
model.add(Dense(1,kernel_initializer="normal",use_bias=True,bias_initializer=Constant(value=1000)))

model.compile(loss='mean_squared_error', optimizer='adam')

model.fit(x_data.values,y_data.values,epochs=1000,validation_split=0.25,verbose=1,batch_size=200)

model.save("model.out")

results = model.predict(x_data.values)

print "Result: ", score(results,y_data.values)

print model.evaluate(x_data.values,y_data.values)
