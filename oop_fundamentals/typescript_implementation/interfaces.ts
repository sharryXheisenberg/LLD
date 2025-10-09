// They allow different parts of the system to interact through well-defined contracts without needing to know how the behavior is actually implemented.
// an interface defines a contract: a set of method signatures that any implementing class must fulfill. It declares what a class can do, but not how it does it.


interface PaymentGateway{
    initiatePayment(amount: number):void;
}
class StripePayment implements PaymentGateway{
    initiatePayment(amount:number):void{
        console.log(`Processing payment via strip: $${amount}`);
    }
}
class RazorPayPayment implements PaymentGateway{
    initiatePayment(amount:number):void{
        console.log(`Payment is processig via Razorpay: $${amount}`);
    }
}
class PaypalPayment implements PaymentGateway{
    initiatePayment(amount:number):void{
        console.log(`Payment is processing via Paypal: $${amount}`);
    }
}
//  StripePayment ,  RazorpayPayment and Paypal implement the same interface, but the actual logic for processing the payment is different.

//  Loose Coupling in Action

class CheckoutService{
    private paymentGateway:PaymentGateway;
    constructor(payementGateway:PaymentGateway){
        this.paymentGateway=payementGateway;
    }
    setPaymentGateway(payementGateway:PaymentGateway){
        this.paymentGateway=payementGateway;
    }
    checkout(amount:number):void{
        this.paymentGateway.initiatePayment(amount);
    }
}

function main():void{
    const stripeGateway:PaymentGateway = new StripePayment();
    const service = new CheckoutService(stripeGateway);
    service.checkout(120.50);

    const razorPayment:PaymentGateway = new RazorPayPayment();
    service.setPaymentGateway(razorPayment);
    service.checkout(150.50);

    const payPalPayment:PaymentGateway = new PaypalPayment();
    service.setPaymentGateway(payPalPayment);
    service.checkout(100.11);

}
main();