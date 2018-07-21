
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from matplotlib import pyplot as plt
from sklearn.model_selection import cross_val_score
from sklearn import metrics
from sklearn.model_selection import KFold
from sklearn.ensemble import AdaBoostRegressor
from sklearn.metrics import mean_squared_error
##reading the data file as dataframe
df = pd.read_csv("inp2.csv",sep = "	 ",engine='python')
##separating the target data(kss score)
target = df["fatigue"]
t=df["hrs"]
del df["fatigue"]
X=df##features are in X
y=target##target is in y
##splitting data into test and train data,with test data 20% of overall data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)
##training with AdaboostRegressor
lm = AdaBoostRegressor(learning_rate=0.1,loss='square',n_estimators=1000)
model = lm.fit(X_train, y_train)
##finding prediction for overall data set to find RMS error
y_pred = lm.predict(X)
##pred of test data
pred = lm.predict(X_test)
##plot
##plt.scatter(y_test, pred)
plt.plot(y,label='True Value')
plt.plot(y_pred,label='predicted')
plt.savefig('Compare')
import math
rms = math.sqrt(mean_squared_error(y, y_pred))
print "RMS Error:", rms
##finding accuracy of our model
print "Score:", model.score(X_test, y_test)*100
##for improving accuracy Cross validation can be done
"""
shuffle = KFold( n_splits=10, shuffle=True, random_state=1)
scores = cross_val_score(model, X, y, cv=shuffle)
mean = scores.mean()
print "score after Cross Valiation", np.sqrt(mean)*100
"""
