# Mahta Zarie calculator project with python
# supports pemdas , parenthesis and float numbers
# this calculator works based on 4 operation + , - , / , *
# the project will support the inputs with spaces


#Function that check if the number's format is float or not
from operator import contains


# def isfloat(num):
#     try:
#         num[0]
#         return True
#     except ValueError:
#         return False



def check_float(potential_float):
    try:

        float(potential_float)
        return True

    except ValueError:

        return False




#the main Function where calculations happen
def calculate(expretion):

    # checking the format of the inputs
    if check_float(expretion):
        return float(expretion)
    if expretion[1] == '-':
        return float(expretion)
    for character in ('+','-','*','/'):
        parts = expretion.partition(character) 
        if parts[1] == '*':
            return str(calculate(parts[0]) * calculate(parts[2]))
        elif parts[1] == '/':
            return str(calculate(parts[0]) / calculate(parts[2]))
        elif parts[1] == '+':
            return str(calculate(parts[0]) + calculate(parts[2]))
        elif parts[1] == '-':
            diff = calculate(parts[0]) - calculate(parts[2])
            if diff < 0:
                sign = '-'
            else:
                sign = ''
            return sign+'%d:%02d' % divmod(abs(diff), 60)
            # return str(calculate(parts[0]) - calculate(parts[2]))

   

def containsAny(str):
    for c in ['(' , ')' , '+' , '-' , '/' ,'*']:
        if c in str:
            return False
    return True

   
def pemdas(s): 

    Exp = []
    i = 0
    j = 0
    s = list(s)
    # e=s

    # str_exp = str

    while i<=len(s):

        if(i == len(s)):
            str_exp = ''.join(Exp)
            return str(calculate(str_exp))

        elif s[i] == '(':
           
            s= pemdas(s[i+1:len(s)])
            # s[i:len(result)]=result
            # if(i-2>0):
            #     i=i-2
            # if(i-1>0):
            #     i=i-1
            # print(s)

        elif(s[i] == ')'):
            str_exp = ''.join(Exp)
            # print(s)
            if(check_float(str_exp)):
                s.pop(i)
                return s
            if(i < len(s) ):
                # s.insert(calculate(str_exp))
                # result = calculate(str_exp)
                if all(item in s for item in Exp):
                    k=0
                    while(Exp[0] != s[k]):
                        k=k+1
                    del s[k:i]
                    # s.remove()
                    s.insert(k, calculate(str_exp))
                    # s.pop(i+1)
                # + s[i+1:len(s)]
                #  i=i-2
                return s
            return str(calculate(str_exp))
        if(Exp != [] and all(item in s for item in Exp)==False):
            # Exp = list(Exp)
            # Exp = Exp + s[0]
            Exp.append(s[0])
            # s.append(Exp)
            # s= Exp + s[0]
            str_exp = ''.join(Exp)
            s= str(calculate(str(str_exp)))
            # s.insert(i,Exp)
            return s

        else:
            j=i
            if(containsAny(s[j])):
                Exp.append(s[j])
                j=j+1
            else:
                Exp.append(s[i])
            i=i+1

        # if(isfloat(s)):
        #     return s
           

       
    return (s)




# print(ret('1+2/2'))

op = str(input("Enter your operantion:"))
# supporting space
op = op.replace(" ", "")
obj = pemdas(op)

# result = round(float(obj),2)
print(obj)