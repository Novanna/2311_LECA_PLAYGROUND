# Import necessary libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

# Generate synthetic student data
np.random.seed(42)
num_students = 100
study_hours = np.random.uniform(1, 10, num_students)
scores = 75 + 5 * study_hours + np.random.normal(0, 5, num_students)

# Create a DataFrame
student_data = pd.DataFrame({'StudyHours': study_hours, 'Scores': scores})

# Display the first few rows of the data
print(student_data.head())

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(student_data[['StudyHours']], student_data['Scores'], test_size=0.2, random_state=42)

# Create and train the linear regression model
lin_reg = LinearRegression()
lin_reg.fit(X_train, y_train)

# Make predictions on the test set
y_pred = lin_reg.predict(X_test)

# Evaluate the model
mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")

# Plot the data and the linear regression line
plt.scatter(X_test, y_test, color='black')
plt.plot(X_test, y_pred, color='blue', linewidth=3)
plt.xlabel('Study Hours')
plt.ylabel('Scores')
plt.title('Linear Regression Example with Student Data')
plt.show()