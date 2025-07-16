# Orderbook

Distributed Lab test task. 
A simple digital order book for exchanging two assets: UAH and USD.


## Description

The program stores two kinds of orders (sell and buy) in two priority queues and automatically matches orders when the top buy price ≥ top sell price.

When orders match, the trade is completed with the price of the earlier order and the resulting balance changes are printed.

- **Base asset:** UAH  
- **Quote asset:** USD


## Technologies
- **Language:** C++17  
- **Build system:** GNU Make on Ubuntu (Linux)  

## How to run
1. Clone the project to a folder on your device:
   
   ```bash
   git clone https://github.com/kamawui/Orderbook.git
   ```
   
2. Navigate to the project folder:
   
   ```bash
   cd Orderbook
   ```
   
3. Compile the program:
   
   ```bash
   make
   ```
   
4. Run the program:
   ```bash
   ./orderbook
   ```

## Usage
Each order is entered in format: 
```bash
<user_id> <amount> <price> <side>
```
- user_id — integer
- amount — UAH amount
- price — USD price per UAH
- side — buy or sell (enter 1 to buy or 0 to sell)

To stop the program enter:
```bash
q
```

## Example
<img width="921" height="776" alt="image" src="https://github.com/user-attachments/assets/2c27b100-8d91-46e4-9aa8-5157487e8b42" />


## Efficiency and complexity
- Adding new order to the priority queue — O(logN), N - number of orders in queue.
- Comparing top buy price ≥ top sell price — O(1).
- Matching orders — O(logN), N - number of orders in queue.

In total:
- Worst case — O(MlogM), M - number of orders in both queues.
- Average case - O(logN).

## Time to implement the task
Up to 4 hours.
