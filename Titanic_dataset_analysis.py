import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import LabelEncoder

# Load Data
df = pd.read_csv("C:\\Users\\kkani\\OneDrive\\Documents\\titanic-Naive Bayes.csv")

# Data Cleaning
df.fillna(0, inplace=True)
df.drop_duplicates(inplace=True)

df['Sex'] = df['Sex'].map({'female': 1, 'male':0})

# Data Exploration
label_encoder = LabelEncoder()
df['Name'] = label_encoder.fit_transform(df['Name'])

print(df.describe())

correlation_matrix = df.corr()
print(correlation_matrix)


# Data Visualization
survival_by_sex = df.groupby('Sex')['Survived'].mean()
survival_by_sex.plot(kind='bar')
plt.title('Survival Rate by Sex')
plt.xlabel('Sex')
plt.ylabel('Survival Rate')
plt.xticks(ticks=[0, 1], labels=['male', 'female'])
plt.show()

df['Age'].hist()
plt.title('Age distribution')
plt.xlabel('Age')
plt.ylabel('Frequency')
plt.show()

plt.figure(figsize=(10, 8))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm')
plt.title('Correlation Heatmap')
plt.show()

plt.scatter(df['Age'], df['Survived'])
plt.title('Age Vs Survived')
plt.xlabel('Age')
plt.ylabel('Survived')
plt.show()

# Advanced Analysis
array = df[['Age','Survived']].to_numpy()
mean_value = np.mean(array)
print(f'Mean Value: {mean_value}')

# Export Results
df.to_csv('cleaned_data.csv', index=False)
