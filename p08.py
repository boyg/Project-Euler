from math import log

'''
Find the thirteen adjacent digits in the 1000-digit number 
that have the greatest product. What is the value of this product?
'''
haystack = (
    '73167176531330624919225119674426574742355349194934'
    '96983520312774506326239578318016984801869478851843'
    '85861560789112949495459501737958331952853208805511'
    '12540698747158523863050715693290963295227443043557'
    '66896648950445244523161731856403098711121722383113'
    '62229893423380308135336276614282806444486645238749'
    '30358907296290491560440772390713810515859307960866'
    '70172427121883998797908792274921901699720888093776'
    '65727333001053367881220235421809751254540594752243'
    '52584907711670556013604839586446706324415722155397'
    '53697817977846174064955149290862569321978468622482'
    '83972241375657056057490261407972968652414535100474'
    '82166370484403199890008895243450658541227588666881'
    '16427171479924442928230863465674813919123162824586'
    '17866458359124566529476545682848912883142607690042'
    '24219022671055626321111109370544217506941658960408'
    '07198403850962455444362981230987879927244284909188'
    '84580156166097919133875499200524063689912560717606'
    '05886116467109405077541002256983155200055935729725'
    '71636269561882670428252483600823257530420752963450')

'''
Determines if the product of digits in first_num 
is larger than the product of digits in second_num
'''
def product_is_larger(first_str, second_str):
    first_chars = list(first_str)
    first_nums = [int(char) for char in first_chars]
    first_sum = 0
    for num in first_nums:
        first_sum += log(num)

    second_chars = list(second_str)
    second_nums = [int(char) for char in second_chars]
    second_sum = 0
    for num in second_nums:
        second_sum += log(num)
    
    if first_sum > second_sum:
        return True
    else:
        return False

'''Finds the product of the digits in a string'''
def calculate_product(section):
    chars = list(section)
    nums = [int(char) for char in chars]
    total = 1
    for num in nums:
        total *= num
    return total

'''Set the high score to be the starting position'''
SLIDER_LENGTH = 13
needle = haystack[0:SLIDER_LENGTH]

'''Begin moving the slider'''
i = 1
while i < len(haystack) - SLIDER_LENGTH:
    section = haystack[i:i+SLIDER_LENGTH]
    if '0' in section: # does there need to be an out-of-bounds check here?
        zero_index = i + section.index('0')
        i += zero_index
    else: 
        if product_is_larger(section, needle):
            needle = section
        i += 1

print(calculate_product(needle))