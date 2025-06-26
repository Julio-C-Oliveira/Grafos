Repositório pra armazenar uns bagulhos de grafos.

Até agora ele contém:
- Grafo por Lista.
- Grafo por Matriz.
- DFS.
- BFS.
- BFS com a funcionalidade de encontrar um caminho entre um vértice inicial e outro, o programa deve retornar o tamanho do caminho.
- DFS com a funcionalidade de encontrar ciclo e apresentar o ciclo encontrado no DFS, após encontrar o primeiro ciclo o algoritmo deve ser encerrado. Professor disse algo com relação a encontrar outro nó cinza.
- [ ] Implementar o algoritmo de Fleury. 
- [ ] Implementar o algoritmo heurístico de Bellmore e Neuhauser. 

Vou começar a utilizar o seguinte padrão para commits:

<tipo>[escopo opcional]: <descrição breve>

[corpo opcional]

[rodapé opcional]

Tipos comuns:
- feat: Pra adição de funcionalidade.
- fix: Pra correção de bugs.
- docs: Pra alterações de documentação.
- style: Mudança de formatação (espaços, vígulas e etc...) coisas que não afetam o código.
- refactor: Refatoração do código, sem adicionar novas funcionalidades ou corrigir bugs.
- test: Adição ou ajuste de testes.
- chore: Manutenção, atualização de dependências, configurações e etc...

Ex: feat(autenticação): adiciona login via Google

Vou tentar seguir algumas regras também:
- Limite de 50 a 72 caracteres no titulo.
- Uso do imperativo, adiciona ao invés de adicionei ou adicionando.
- Corpo explicativo se precisar, para explicar o porquê e como a alteração foi feita.
- Deixar uma linha em branco entre o assunto, o corpo e o rodapé.

Vi também que existe o padrão de emoji, mas não vou usar:
- :sparkles: Pra adição de funcionalidade.
- :bug: Pra correção de bugs.
- :memo: Pra alterações de documentação.

Exemplo que eu vou tentar seguir:

fix(api): corrige timeout na requisição de pagamento

O timeout estava ocorrendo devido a um valor incorreto no header 'Connection'.
Foi ajustado para 30s conforme documentação oficial.

Fixes #123