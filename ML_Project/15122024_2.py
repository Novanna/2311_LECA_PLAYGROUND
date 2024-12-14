# Import necessary libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Load a student dataset (you can replace this with your own dataset)
# For demonstration, we'll use the 'Student Performance' dataset from UCI ML Repository
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/00320/student.zip"
df = pd.read_csv(url, compression='zip', sep=';')

# Select relevant features
features = ['studytime', 'failures', 'absences']
X = df[features]
y = df['G3']  # Final grade as the target variable

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create and train the linear regression model
lin_reg = LinearRegression()
lin_reg.fit(X_train, y_train)

# Make predictions on the test set
y_pred = lin_reg.predict(X_test)

# Evaluate the model
mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")

# Plot the results
plt.scatter(X_test['studytime'], y_test, color='black', label='Actual')
plt.scatter(X_test['studytime'], y_pred, color='blue', label='Predicted')
plt.xlabel('Study Time')
plt.ylabel('Final Grade (G3)')
plt.title('Linear Regression Example with Student Data')
plt.legend()
plt.show()