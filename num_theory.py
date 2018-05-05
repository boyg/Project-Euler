from math import gcd

def multi_lcm(num_list):
    '''
    num_list: list of integers
    returns: LCM (least common multiple) of the numbers in the list
    '''
    lcm = num_list[0]

    for i in num_list[1:]:
        lcm = (lcm * i) // gcd(lcm, i)
        
    return lcm