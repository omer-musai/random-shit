def read_stations(file_path):
    with open(file_path, 'r') as infile:
        lines = infile.readlines()


    lines = [[l for l in p.strip('\n').split(' ') if l != ''] for p in lines] # get rid of '\n'
    
    d = {}
    for line in lines:
        a_to_b = (line[1], float(line[2]), [])
        b_to_a = (line[0], float(line[2]), [])
        if line[0] in d:
            d[line[0]] += [a_to_b]
        else:
            d[line[0]] = [a_to_b]

        if line[1] in d:
            d[line[1]] += [b_to_a]
    
        else:
            d[line[1]] = [b_to_a]
    return d


print (read_stations(r'C:\Users\omer\Desktop\a b 1.txt'))
