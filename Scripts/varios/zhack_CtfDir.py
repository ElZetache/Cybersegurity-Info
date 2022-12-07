import os

ctf_name = "ExampleCTF"  # Nombre del CTF

# Crear directorio raíz para el CTF
root_dir = os.path.join(os.getcwd(), ctf_name)
os.makedirs(root_dir, exist_ok=True)

# Crear directorios para cada categoría del CTF
categories = ["Web", "Crypto", "Forensics", "Reverse Engineering"]
for category in categories:
    category_dir = os.path.join(root_dir, category)
    os.makedirs(category_dir, exist_ok=True)

# Cambiar al directorio raíz del CTF
os.chdir(root_dir)