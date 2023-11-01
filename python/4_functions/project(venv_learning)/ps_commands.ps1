# Temos que setar a execution policy para "unrestrict"

# O código pode ser executado direto no PowerShell, está aqui apenas afim
# de anotação.

# https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.security/set-executionpolicy?view=powershell-7.3

Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scrop CurrentUser

Get-ExecutionPolicy -List

# Vamos criar um ambiente virtual, o comando é o mesmo para Linux, Mac e Windows

# ".venv" é o nome do nosso ambiente virtual
python -m venv .venv