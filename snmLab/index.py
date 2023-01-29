# simple stock portfolio with fixed return rate and volatility
# using Monte Carlo Method

import random
import pandas as pd

def financial_system(num_years,return_rate, volatility):
    returns = []

    for i in range(num_years):
        # generating random number from normal/gauss distribution
        r = return_rate + volatility *random.gauss(0,1)
        returns.append(r)
    
    return returns

# Run the simulation
num_samples = 10000
initial_value = 10000
num_years = 5
return_rate = 0.08
volatility = 0.2
final_values = []

for i in range(num_samples):
    returns = financial_system(num_years, return_rate, volatility)
    final_value = initial_value

    for r in returns:
        final_value *=(1+r)
    final_values.append(final_value)

# writing the final portfolio values to an excel file
df = pd.DataFrame(final_values, columns=['Final Portfolio Value'])
df.to_excel("final_port.xlsx")