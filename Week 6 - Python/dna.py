import csv
import sys


def longest_match(sequence, subsequence):
    """En uzun tekrar eden STR dizisini bulur"""
    longest = 0
    sub_len = len(subsequence)
    seq_len = len(sequence)

    for i in range(seq_len):
        count = 0
        while True:
            start = i + count * sub_len
            end = start + sub_len
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest = max(longest, count)
    return longest


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    with open(sys.argv[1], newline='') as file:
        reader = csv.DictReader(file)
        str_list = reader.fieldnames[1:]
        people = list(reader)

    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    str_counts = {}
    for STR in str_list:
        str_counts[STR] = longest_match(sequence, STR)

    for person in people:
        match = all(int(person[STR]) == str_counts[STR] for STR in str_list)
        if match:
            print(person["name"])
            return

    print("No match")


if __name__ == "__main__":
    main()
