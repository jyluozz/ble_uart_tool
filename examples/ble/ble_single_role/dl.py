import datetime
import os
import sys

import winreg

def get_jlink_file():
    jlink_file = ''
    key = winreg.OpenKey(winreg.HKEY_CURRENT_USER,r"Software\\SEGGER\\J-LINK")
    try:
        value, type = winreg.QueryValueEx(key, "InstallPath")
        if value is not None:
            jlink_file = os.path.join(value,"jlink.exe")
    except WindowsError:
        pass
    return jlink_file

def download_hex(jlink_file = None,hex_path = None,hex_file_ext = None,device_name = None):
    """jlink_file:jlink文件路径;hex_path:hex文件路径;hex_file_ext:查找hex文件关键字;device_name:下载设备名称"""

    if jlink_file is None:
        jlink_file = get_jlink_file()
    print(jlink_file)
    if not os.path.exists(jlink_file):
        print('找不到JLink.exe文件.')
        sys.exit()

    # jlink_file = '..\\..\\..\\tools\\prog\\jlink.exe'
    # if not os.path.exists(jlink_file):
    #     jlink_file = '..\\..\\..\\..\\tools\\prog\\jlink.exe'
    #     if not os.path.exists(jlink_file):
    #         if not os.path.exists(jlink_file):
    #             jlink_file=os.getenv("SystemDrive")+'\\Program Files (x86)\\SEGGER\JLink\\jlink.exe'
    #             if not os.path.exists(jlink_file):
    #                 jlink_file=os.getenv("SystemDrive")+'\\Program Files\\SEGGER\JLink\\jlink.exe'
    #                 if not os.path.exists(jlink_file):
    #                     print('找不到JLink.exe文件.')
    #                     sys.exit()

    if hex_path is None:
        file_dir = '.\\build\\le501x'
    else:
        file_dir = hex_path

    if hex_file_ext is None:
        file_ext = 'production.hex'   # xxxx_production.hex
    else:
        file_ext = hex_file_ext

    file_name = None
    list_dirs = os.walk(file_dir)
    for root, dirs, files in list_dirs:
        for file_temp in files:
            if file_temp.find(file_ext) >= 0 :
                file_name = os.path.join(root, file_temp)
                print(file_name)
                #print('roots=',roots,'dirs=',dirs)
                #print(file_name)
                break
        if file_name is None:
            break

    if file_name is not None:
        # "Device LE501X\n"
        if device_name is None:
            device_name = "LE501X"
        device_name = 'Device ' + device_name + '\n'

        now=datetime.datetime.now()
        script_file = now.strftime("%Y%m%d_%H%M%S.txt")

        script_f = open(script_file,"w")
        script_f.write("si 1\n")
        script_f.write("speed 4000\n")
        script_f.write(device_name)
        script_f.write("r\n")
        script_f.write("h\n")
        script_f.write("erase\n")
        script_f.write("loadfile " + file_name + '\n')
        script_f.write("qc\n")
        script_f.close()

        '''
        script_f = open(script_file,"w")
        script_f.write("SelectInterface SWD\n")
        script_f.write("Speed 4000\n")
        script_f.write("Device LE501X\n")
        script_f.write("Reset\n")
        script_f.write("Halt\n")
        script_f.write("Erase\n")
        script_f.write("LoadFile " + file_name + '\n')
        script_f.write("Exit\n")
        script_f.close()
        '''

        exe_cmd = '"'+ jlink_file+ '"'+ ' .\\' + script_file

        print('exe_cmd:',exe_cmd)
        os.system(exe_cmd)

        try:
            os.remove(script_file)
        except Exception:
            pass
    else:
        print("找不到hex文件.")

if __name__ == '__main__':
    # def download_hex(jlink_file = None,hex_path = None,hex_file_ext = None,device_name = None):

    # download_hex("C:/Program Files (x86)/SEGGER/JLink/jlink.exe", "./build/gemini","production.hex","LM30XX")
    # download_hex("C:/Program Files (x86)/SEGGER/JLink/jlink.exe", "./build/le501x","production.hex","LE501X")
    # download_hex(None, "./build/xxx",None,"xxxx")

    # 不带参数,默认是: jlink 注册表路径"./build/le501x","production.hex","LE501X"
    download_hex()
    # download_hex('.\\LS_SDK_R1.1\\tools\\prog\\JLink.exe')

#使用:
# c:\ls_sdk>python dl.py
