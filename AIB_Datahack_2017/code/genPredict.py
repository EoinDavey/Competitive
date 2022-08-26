import numpy as np
import pandas as pd
import sys
from keras.models import load_model

model = load_model("model.out")

filename = sys.argv[1]

data = pd.read_csv(filename)

x_data = data[['AWND','PRCP','SNOW','TAVG','TMAX','TMIN','Holiday']]

wkday = data.ix[:,'Weekday']
wkday = wkday.apply(lambda x: 0 if x < 5 else 1)
x_data = pd.concat([wkday.to_frame(),x_data],axis=1)

pred = model.predict(x_data.values)

dfout = pd.concat([data[['ID']],pd.Series(pred[:,0])],axis=1)
dfout.columns = ['ID','Total']

print dfout.head()

dfout.to_csv("prediction.csv",index=0)
