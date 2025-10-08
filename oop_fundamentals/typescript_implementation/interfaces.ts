interface PaymentGateway {
    initiatePayment(amount: number): void;
}
