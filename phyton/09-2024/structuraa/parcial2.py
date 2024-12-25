class Stack:
    def __init__(self, max_size):
        self.max_size = max_size
        self.size = 0
        self.data = [None] * max_size

    def is_empty(self):
        return self.size == 0
    
    def is_full(self):
        return self.max_size == self.max_size

    def push(self, element):
        if self.size >= self.max_size:
            raise OverflowError("List is full")
        self.data[self.size] = element
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("List is empty")
        self.size -= 1
        return self.data[self.size]

    def print(self):
        print("{ ", end="")
        for i in range(self.size):
            print(self.data[i], end=", " if i < self.size - 1 else "")
        print(" }")
        
if __name__ == '__main__':
    n = input()
    n = n.split('/')
    answer = Stack(len(n))
    answer.push(n[0])
    for i in n [1:]:
        print(i)
        if i.find('/'):
            answer.push(i)
    answer.print()