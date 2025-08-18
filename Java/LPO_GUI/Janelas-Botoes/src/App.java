/* 
 * Documentação: https://web.mit.edu/6.005/www/sp14/ps...
*/


import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class App {
    public static void main(String[] args) throws Exception {
        
        /* >> Janela */
        JFrame janela = new JFrame();
        
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Fecha o programa ao fechar a janela
        janela.setBounds(2400, 200, 400,600); // Define o tamanho da janela
        janela.setVisible(true); // Agora precisamos deixar a janela visível
        janela.setLayout(null); // Escolhe o layout da janela
                                // Aqui deixaremos nulo para termos liberdade de onde colocar o botao

        /* >> Label -> um texto que não pode ser digitado*/
        JLabel labelUsuario = new JLabel("Usuário:");
        JLabel labelSenha = new JLabel("Senha:");
        
        labelUsuario.setBounds(50,50, 100,30);
        labelSenha.setBounds(50,100, 100,30);
        
        janela.add(labelUsuario);
        janela.add(labelSenha);

        /* TextField -> Um campo para o usário inserir output */
        JTextField campoUsuario = new JTextField();

        campoUsuario.setBounds(110, 50, 150, 30);
        janela.add(campoUsuario);
        
        /* PasswordField */
        JPasswordField campoSenha = new JPasswordField();

        campoSenha.setBounds(110, 100, 150, 30);
        janela.add(campoSenha);

        /* >> Botão */
        JButton botao = new JButton("Login");
        
        janela.add(botao); // Adiciona o Botão a janela
        botao.setBounds(105,150,200,30); // Define tamanho e posição do botao
        // Agora criamos um evento para quando o botão for clicado,
        // nesse caso podemos criar a classe direto dentro dos argumentos

        botao.addActionListener(new ActionListener(){ // Vamos criar um objeto do tipo ActionListener
            @Override
            public void actionPerformed(ActionEvent e) {
                String usuario = campoUsuario.getText();
                String senha = new String(campoSenha.getPassword());

                System.out.printf("%s:%s\n", usuario, senha);
                // Limpa os campos
                campoUsuario.setText("");
                campoSenha.setText("");
            } 
        });


    }
}
