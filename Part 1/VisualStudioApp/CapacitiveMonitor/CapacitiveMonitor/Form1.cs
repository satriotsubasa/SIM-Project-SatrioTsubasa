using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CapacitiveMonitor
{
    public partial class Form1 : Form
    {
        delegate void SetTextCallback(string text);

        private void SetText1(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox1.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText1);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox1.Text = text;
            }
        }
        private void SetText2(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox2.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText2);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox2.Text = text;
            }
        }
        private void SetText3(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox3.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText3);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox3.Text = text;
            }
        }
        private void SetText4(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox4.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText4);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox4.Text = text;
            }
        }

        private void SetText5(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox5.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText5);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox5.Text = text;
            }
        }

        private void SetText6(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox6.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText6);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox6.Text = text;
            }
        }
        private void SetText7(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (this.textBox7.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText7);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.textBox7.Text = text;
            }
        }
        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string data_rx = serialPort1.ReadLine();
            string[] ArrayData = data_rx.Split('#');
            SetText1(ArrayData[0].ToString());
            SetText2(ArrayData[1].ToString());
            SetText3(ArrayData[2].ToString());
            SetText4(ArrayData[3].ToString());
            SetText5(ArrayData[4].ToString());
            SetText6(ArrayData[5].ToString());
            SetText7(ArrayData[6].ToString());

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int value;
            
            if (int.TryParse(textBox4.Text, out value))
            {

                progressBar1.Value = value;
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }
    }
}
