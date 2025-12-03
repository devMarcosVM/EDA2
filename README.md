# Como compilar e rodar (Windows)

Este repositório contém exemplos em C/C++. Aqui estão passos rápidos para compilar, executar e depurar o arquivo `helloword.cpp` (ou qualquer outro arquivo C/C++ ativo) no Windows.

## Pré-requisitos

- GCC (msys2/ucrt64) e GDB instalados em `C:\msys64\ucrt64\bin` (padrão ao usar MSYS2 UCRT64).
- VS Code com extensão C/C++ (Microsoft).

## Compilar usando a task do VS Code

1. Abra o arquivo fonte que quer compilar (por exemplo `LearningCPP/helloword.cpp`).
2. Pressione `Ctrl+Shift+B` para executar a task de build (a task `C/C++: gcc.exe build active file` está configurada no workspace).

Ao final, o executável será criado na mesma pasta do arquivo fonte, com o nome `<fileBasenameNoExtension>.exe`.

## Rodar no Prompt de Comando (cmd)

Abra o `cmd.exe` e troque para a pasta do executável. Exemplo:

```bat
cd /d "c:\Users\marcos.marinho\OneDrive - Funpresp-Jud\Documentos\EDA2\LearningCPP"
helloword.exe
```

Se preferir compilar manualmente no cmd (sem VS Code):

```bat
"C:\msys64\ucrt64\bin\gcc.exe" -g "helloword.cpp" -o "helloword.exe"
.
\helloword.exe
```

## Depurar no VS Code

1. Abri o arquivo fonte que deseja depurar.
2. Coloque breakpoints se desejar.
3. Abra a aba Run & Debug (ícone de execução) e escolha `Debug active file (gdb)`.
4. Pressione F5. O VS Code irá compilar (pré-tarefa) e iniciar o depurador (usa GDB em `C:\msys64\ucrt64\bin\gdb.exe`).

Observações / Assunções

- O `launch.json` criado assume que o GDB está em `C:\msys64\ucrt64\bin\gdb.exe`. Se o seu GDB estiver em outro local, altere `miDebuggerPath` em `.vscode/launch.json`.
- O `preLaunchTask` usa o rótulo `C/C++: gcc.exe build active file` — isso corresponde à task já presente no workspace. Se você mudou o nome da task, atualize o `preLaunchTask`.

Se quiser, eu posso também criar uma `tasks.json` personalizada que compile todo um diretório ou um `Makefile` simples.
# EDA2