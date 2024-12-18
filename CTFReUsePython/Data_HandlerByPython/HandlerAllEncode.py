def convert_to_int_list(input_string, format_type):
    """
    将输入的字符串按不同的格式转换为整数数组。

    参数：
        input_string (str): 输入的字符串（可能是十六进制、十进制、二进制等格式）
        format_type (str): 指定格式类型，支持 'hex', 'dec', 'bin'。

    返回：
        list: 转换后的整数数组
    """
    if format_type == 'hex':
        # 去除空格和逗号，再按两位拆分成列表
        clean_input = input_string.replace(' ', '').replace(',', '')
        result_list = [int(clean_input[i:i+2], 16) for i in range(0, len(clean_input), 2)]
        
    elif format_type == 'dec':
        # 去除空格和逗号，再按三位拆分成列表
        clean_input = input_string.replace(' ', '').replace(',', '')
        result_list = [int(clean_input[i:i+3]) for i in range(0, len(clean_input), 3)]
        
    elif format_type == 'bin':
        # 去除空格和逗号，再按8位拆分成列表
        clean_input = input_string.replace(' ', '').replace(',', '')
        result_list = [int(clean_input[i:i+8], 2) for i in range(0, len(clean_input), 8)]
        
    else:
        raise ValueError("Unsupported format type. Choose from 'hex', 'dec', 'bin'.")

    return result_list


