class Trade:
    value = 0
    decision = None

    def __init__(self, value, decision):
        self.value = value
        self.decision = decision

class Exchange:
    def __init__(self, initialBalance, validTrades):
        self.balance = initialBalance
        self.pending = []  # Initialize the pending list
        self.stock = []
        self.validTrades = set(validTrades)

    def add_trade(self, trade):
        # Check if the decision is in validTrades
        if trade.decision in self.validTrades:
            self.pending.append(trade)

            if trade.decision and self.balance >= trade.value:
                self.stock.append(trade)
                self.pending.remove(trade)
                self.balance -= trade.value
                
                
if __name__ == "__main__":
    validTrades = [Trade(value, decision) for value in range(1, 1000) for decision in [True, False]]

    exchange = Exchange(100, [True, False]) 

    exchange.add_trade(Trade(20, True))
    assert exchange.balance == 80 
    
    exchange.add_trade(Trade(10, False))
    assert exchange.balance == 80

    
    exchange.add_trade(Trade(30, True))
    exchange.add_trade(Trade(15, False))
    exchange.add_trade(Trade(25, False))
    assert exchange.balance == 50


    exchange.add_trade(Trade(50, True))
    assert exchange.balance == 0


    exchange.add_trade(Trade(10, True))
    exchange.add_trade(Trade(15, True))
    assert exchange.balance == 0
     

    print("Tests passed!")