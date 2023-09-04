import sys

def factorize(nb):
    fct = []
    x = 2
    while x * x <= nb:
        while nb % x == 0:
            fct.append(x)
            nb //= x
        else:
            x += 1
    if nb > 1:
        fct.append(nb)
    return (fct)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print('Usage: python factors.py <file>')
        sys.exit(1)
    input_filename = sys.argv[1]

    try:
        with open(input_filename, 'r') as file:
            for li in file:
                nb = int(li.strip())
                fcts = factorize(nb)
                fcts_str = "*".join(map(str, fcts))
                print(f"{nb}={fcts_str}")
    except FileNotFoundError:
        print(f"Error: Can't open file '{input_filename}'")
        sys.exit(1)
