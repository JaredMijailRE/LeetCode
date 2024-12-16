class factory():
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
                
    def evaluation(self, scores: staticStack):
        differences = [abs(scores.data[i] - scores.data[i + 1]) for i in range(1, scores.size-1)]
        expected = list(range(1, scores.size-1))
        if sorted(differences) == expected:
            print("Jolly")
        else:
            print("Not jolly")
            
    def str_to_stack(self, line: str)-> staticStack:
        scores = line.split(' ')
        stack = self.staticStack(len(scores))
        for element in scores:
            stack.add(int(element))
        return stack
            
if __name__ == '__main__':
    while(True):
        try:
            UNAL = factory()
            line = input()
            scores = UNAL.str_to_stack(line)
            UNAL.evaluation(scores)
        except:
            break


