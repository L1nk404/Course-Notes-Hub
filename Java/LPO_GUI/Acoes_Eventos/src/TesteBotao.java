
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class TesteBotao {
	
	public void testeBotao() {
		
		// Primeiro vamos fazer uma janela para colocar o botao
		JFrame janela = new JFrame();
		
		// Agora vamos criar o botao e colocar na janela
		JButton botao = new JButton("Botao Teste");
		janela.add(botao);
		
		// Agora vamos criar a acao usando inner class
		// (poderia ser criada de qualquer jeito, desde que implemente ActionListener)
		AcaoBotao acaoBotao = new AcaoBotao();
		
		// Vamos inserir a acao no botao
		botao.addActionListener(acaoBotao);
		
		// Agora vamos fazer algumas configuracoes que vamos aprender mais adiante para que servem
		// 1 - redimensiona para caber todos componentes
		janela.pack(); 
		// 2 - configura para terminar o programa quando a janela for fechada
		janela.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		// 3 - torna a janela visivel
		janela.setVisible(true);
		
	}
	
	// Este eh o ActionListener que vai ser inserido no botao
	class AcaoBotao implements ActionListener{

		// Um action listener deve ter um actionPerformed
		// esta eh a acao que sera acionada quando o botao (evento) for pressionado
		@Override
		public void actionPerformed(ActionEvent e) {
			System.out.println("O Botao foi pressionado!");
		}
		
	}
	
	public static void main(String[] args) {
		new TesteBotao().testeBotao();
	}

}