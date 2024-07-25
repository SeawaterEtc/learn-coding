def convert_to_zeros(text):
    return ''.join('_' if char != ' ' else ' ' for char in text)

# Example usage
input_text = input()
output_text = convert_to_zeros(input_text)
print(output_text)  # output based on return statement
