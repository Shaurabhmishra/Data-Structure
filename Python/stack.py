class Stack:
    def __init__(self):
        self.items = []
    
    def push(self, val):
        self.items.append(val)
    
    def pop(self):
        self.items.pop()
    
    def is_empty(self):
        return self.items == []
    
    def peek(self):
        if not self.is_empty():
            return self.items[-1]

    def get_stack(self):
        return self.items

s1 = Stack()
print(s1.is_empty())
s1.push("A")
s1.push("B")
s1.push("C")
s1.push("D")
s1.push("E")
print(s1.is_empty())
print(s1.get_stack())
print(s1.peek())