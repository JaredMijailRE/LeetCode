class sia():
    class staticStack():
        def __init__(self, size: int):            
            self.data = [None]*size
            self.size = 0
        
        def pop(self):
            if(self.size == 0):
                print('Non element to delete')
            else: self.size -= 1
            
        def add(self, value: int):
            if(self.size == len(self.data)):
                print('list is full')
            else:
                self.data[self.size] = value
                self.size += 1
        
        def get_last(self):
            return self.data[self.size-1]
        
        def print_list(self):
            print("", end="")
            for i in range(self.size):
                print(self.data[i], end=" " if i < self.size - 1 else "")
            print("")

                
    def gis(self, data: str, size: int):
        answer = self.staticStack(size)
        answer.add(int(data[0]))
        for letter in data:
            if(letter == ' '):
                pass
            else:
                letter = int(letter) 
                if(letter > answer.get_last()):
                    answer.add(letter)

        print(answer.size)
        answer.print_list()
        
            
if '__main__' == __name__:
    answer = sia()
    size = input()
    data = input()
    answer.gis(data, int(size))
    